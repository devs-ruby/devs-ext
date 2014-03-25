#ifndef DEVS_NATIVE
#define DEVS_NATIVE

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <float.h>

#include <ruby.h>

#include <processor.h>
#include <coordinator.h>
#include <atomic_model.h>
#include <coupled_model.h>
#include <classic_simulator_impl.h>
#include <classic_coordinator_impl.h>
#include <classic_root_coordinator_strategy.h>
#include <parallel_simulator_impl.h>
#include <parallel_coordinator_impl.h>
#include <parallel_root_coordinator_strategy.h>

extern const float EPSILON;

extern ID DISPATCH_ID;

extern VALUE mDEVS;
extern VALUE mDEVSClassic;
extern VALUE mDEVSParallel;

extern VALUE cDEVSNoSuchChildError;
extern VALUE cDEVSBadSynchronisationError;
extern VALUE cDEVSInvalidPortTypeError;
extern VALUE cDEVSInvalidPortHostError;
extern VALUE cDEVSMessageAlreadySentError;
extern VALUE cDEVSFeedbackLoopError;

extern VALUE cDEVSEvent;
extern VALUE cDEVSMessage;

void devs_debug(const char *file, int lines, char *fmt, ...);

// compare floating point numbers
bool fneq(const double a, const double b, const float epsilon);

// #define DEBUG

#define FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#ifdef DEBUG
#define DEVS_DEBUG(fmt...) devs_debug(FILE, __LINE__, fmt);
#else
#define DEVS_DEBUG(fmt...)
#endif

#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

#ifndef RARRAY_PTR
#define RARRAY_PTR(a) RARRAY(a)->ptr
#endif

#ifndef RARRAY_LEN
#define RARRAY_LEN(a) RARRAY(a)->len
#endif

#ifndef INFINITY
#define INFINITY 1.0 / 0.0
#endif

#endif
