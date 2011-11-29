#include "ruby.h"
#include <stdio.h>
#include "analyze_image.h"

static VALUE rb_cImageCore;

static VALUE analyze(VALUE klass, VALUE filename)
{
//  fprintf(stderr, "klass type %d filename type %d\n", TYPE(klass), TYPE(filename));

  Check_Type(filename, T_STRING);

  char *fn = StringValueCStr(filename);

  int threshold = 150;
  int tlx, tly, brx, bry;

  bool res = image_core_analyze_image(fn, threshold, tlx, tly, brx, bry);


  return Qnil;
}

extern "C" void Init_imagecore()
{
  rb_cImageCore = rb_define_class("ImageCore", rb_cObject);
  rb_define_singleton_method(rb_cImageCore, "analyze", (VALUE(*)(ANYARGS))analyze, 1);
}
