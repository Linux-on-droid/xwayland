#ifndef _XSERVER_OS_BUG_H
#define _XSERVER_OS_BUG_H

#include "os.h"

/* Don't use this directly, use BUG_WARN or BUG_WARN_MSG instead */
#define __BUG_WARN_MSG(cond, with_msg, ...)                                \
          do { if (cond) {                                                \
              ErrorFSigSafe("BUG: triggered 'if (" #cond ")'\n");          \
              ErrorFSigSafe("BUG: %s:%u in %s()\n",                        \
                           __FILE__, __LINE__, __func__);                 \
              if (with_msg) ErrorFSigSafe(__VA_ARGS__);                    \
              xorg_backtrace();                                           \
          } } while(0)

#define BUG_WARN_MSG(cond, ...)                                           \
          __BUG_WARN_MSG(cond, 1, __VA_ARGS__)

#define BUG_WARN(cond)  __BUG_WARN_MSG(cond, 0, NULL)

#define BUG_RETURN(cond) \
        do { if (cond) { __BUG_WARN_MSG(cond, 0, NULL); return; } } while(0)

#define BUG_RETURN_MSG(cond, ...) \
        do { if (cond) { __BUG_WARN_MSG(cond, 1, __VA_ARGS__); return; } } while(0)

#define BUG_RETURN_VAL(cond, val) \
        do { if (cond) { __BUG_WARN_MSG(cond, 0, NULL); return (val); } } while(0)

#define BUG_RETURN_VAL_MSG(cond, val, ...) \
        do { if (cond) { __BUG_WARN_MSG(cond, 1, __VA_ARGS__); return (val); } } while(0)

#endif /* _XSERVER_OS_BUG_H */