
#ifndef LOGIC_PLUGIN_EXPORT_H
#define LOGIC_PLUGIN_EXPORT_H

#ifdef LOGIC_PLUGIN_STATIC_DEFINE
#  define LOGIC_PLUGIN_EXPORT
#  define LOGIC_PLUGIN_NO_EXPORT
#else
#  ifndef LOGIC_PLUGIN_EXPORT
#    ifdef logic_plugin_EXPORTS
        /* We are building this library */
#      define LOGIC_PLUGIN_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LOGIC_PLUGIN_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LOGIC_PLUGIN_NO_EXPORT
#    define LOGIC_PLUGIN_NO_EXPORT 
#  endif
#endif

#ifndef LOGIC_PLUGIN_DEPRECATED
#  define LOGIC_PLUGIN_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LOGIC_PLUGIN_DEPRECATED_EXPORT
#  define LOGIC_PLUGIN_DEPRECATED_EXPORT LOGIC_PLUGIN_EXPORT LOGIC_PLUGIN_DEPRECATED
#endif

#ifndef LOGIC_PLUGIN_DEPRECATED_NO_EXPORT
#  define LOGIC_PLUGIN_DEPRECATED_NO_EXPORT LOGIC_PLUGIN_NO_EXPORT LOGIC_PLUGIN_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LOGIC_PLUGIN_NO_DEPRECATED
#    define LOGIC_PLUGIN_NO_DEPRECATED
#  endif
#endif

#endif /* LOGIC_PLUGIN_EXPORT_H */
