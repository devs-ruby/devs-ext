#include <coupled_model.h>

VALUE cDEVSAtomicModel;

static VALUE fetch_output_bang(VALUE self);

/*
* Document-class: DEVS::AtomicModel
*/
void
init_devs_atomic_model() {
    VALUE mdl = rb_define_class_under(mDEVS, "Model", rb_cObject);
    VALUE klass = rb_define_class_under(mDEVS, "AtomicModel", mdl);

    cDEVSAtomicModel = klass;

    rb_define_method(klass, "fetch_output!", fetch_output_bang, 0);
}

/*
* call-seq:
*   fetch_output!
*
* Yield outgoing messages added by the DEVS lambda (λ) function for the
* current state
*
* @note This method calls the DEVS lambda (λ) function
* @api private
* @yieldparam message [Message] the message that is yielded
* @return [Array<Message>]
*/
static VALUE
fetch_output_bang(VALUE self) {
    rb_funcall(self, rb_intern("output"), 0);
    VALUE bag = rb_ary_new();
    VALUE output_ports = rb_iv_get(self, "@output_ports");
    long i;

    for (i = 0; i < RARRAY_LEN(output_ports); i++) {
        VALUE port = rb_ary_entry(output_ports, i);
        VALUE value = rb_funcall(port, rb_intern("pick_up"), 0)
        if (value != Qnil) {
            VALUE msg = rb_funcall(
                cDEVSMessage,
                rb_intern("new"),
                2,
                value,
                port
            );

            if (rb_block_given_p()) {
                rb_yield(msg);
            }

            rb_ary_push(bag, msg);
        }
    }

    return bag;
}
