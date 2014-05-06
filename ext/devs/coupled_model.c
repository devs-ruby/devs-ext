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

    rb_define_private_method(klass, "each_coupling", each_coupling, 2);
}


static VALUE
each_coupling(VALUE self, VALUE ary, VALUE port) {
    VALUE result;
    long i;

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
