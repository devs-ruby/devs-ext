#include <coupled_model.h>

VALUE cDEVSCoupledModel;

static VALUE each_coupling(VALUE self, VALUE ary, VALUE port);

/*
* Document-class: DEVS::CoupledModel
*/
void
init_devs_coupled_model() {
    VALUE mdl = rb_define_class_under(mDEVS, "Model", rb_cObject);
    VALUE klass = rb_define_class_under(mDEVS, "CoupledModel", mdl);

    cDEVSCoupledModel = klass;

    rb_define_method(klass, "each_coupling", each_coupling, 2);
}

/*
* call-seq:
*   each_coupling
*
* Calls <tt>block</tt> once for each coupling in passing that element as a
* parameter. If a port is given, it is used to filter the couplings having
* this port as a source.
*
* @param ary [Array] the array of couplings, defaults to {#couplings}
* @param port [Port, nil] the source port or nil
* @yieldparam coupling [Coupling] the coupling that is yielded
*/
static VALUE
each_coupling(VALUE self, VALUE ary, VALUE port) {
    VALUE result, coupling, port_src;
    long i, len;

    if (NIL_P(ary)) {
        ary = rb_funcall(self, rb_intern("couplings"), 0);
    }

    if (NIL_P(port)) {
        if (rb_block_given_p()) {
            for (i = 0; i < RARRAY_LEN(ary); i++) {
                rb_yield(rb_ary_entry(ary, i));
            }
        }
        result = ary;
    } else {
        result = rb_ary_new();

        for (i = 0; i < RARRAY_LEN(ary); i++) {
            VALUE coupling = rb_ary_entry(ary, i);
            VALUE port_src = rb_iv_get(coupling, "@port_source");

            if (port_src == port) {
                rb_ary_push(result, coupling);
                if (rb_block_given_p()) {
                    rb_yield(coupling);
                }
            }
        }
    }

    return result;
}
