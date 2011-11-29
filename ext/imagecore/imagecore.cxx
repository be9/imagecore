#include "ruby.h"
#include <stdio.h>
#include "analyze_image.h"

static VALUE analyze(VALUE klass, VALUE filename, VALUE thresh)
{
  Check_Type(filename, T_STRING);
  Check_Type(thresh, T_FIXNUM);

  char *fn = StringValueCStr(filename);

  int threshold = NUM2INT(thresh);
  int tlx, tly, brx, bry;

  if (image_core_analyze_image(fn, threshold, tlx, tly, brx, bry)) {
    VALUE arr = rb_ary_new();

    rb_ary_push(arr, INT2FIX(tlx));
    rb_ary_push(arr, INT2FIX(tly));
    rb_ary_push(arr, INT2FIX(brx));
    rb_ary_push(arr, INT2FIX(bry));

    return arr;
  } else
    return Qnil;
}

extern "C" void Init_imagecore()
{
  VALUE module = rb_const_get(rb_cObject, rb_intern("ImageCore"));
  VALUE klass = rb_define_class_under(module, "Ext", rb_cObject);

  rb_define_singleton_method(klass, "analyze", (VALUE(*)(ANYARGS))analyze, 2);
}
