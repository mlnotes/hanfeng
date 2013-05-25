/* 
 * File:   HFIO.h
 * Author: zhf
 *
 * Created on 2013年5月25日, 上午2:07
 */

#ifndef IO_HFIO_H
#define IO_HFIO_H

#include "../base/common.h"
#include "../base/init.h"

namespace hanfeng
{
    class HFIO;
    extern HFIO *hf_io;
    
    
enum EMessageType
{
    MSG_GCDEBUG = 0,
    MSG_DEBUG = 1,
    MSG_INFO = 2,
    MSG_NOTICE = 3,
    MSG_WARNING = 4,
    MSG_ERROR = 5,
    MSG_CRITICAL = 6,
    MSG_ALERT = 7,
    MSG_EMERGENCY = 8,
    MSG_MESSAGEONLY = 9
};
    
#define NUM_LOG_LEVELS 10


#if !defined(HF_UNLIKELY)
#if __GNUC__ >= 3
#define HF_UNLIKELY(expr) __builtin_expect(expr, 0)
#else
#define HF_UNLIKELY(expr) expr
#endif
#endif

#define HF_SPRINT(...) {hf_io->message(MSG_MESSAGEONLY, __FILE__, __LINE__, __VA_ARGS__);}
#define HF_WARNING(...) {hf_io->message(MSG_WARNING, __FILE__, __LINE__, __VA_ARGS__);}
#define HF_ERROR(...) {hf_io->message(MSG_ERROR, __FILE__, __LINE__, __VA_ARGS__);}

#define ASSERT(x){      \
    if(HF_UNLIKELY(!(x)))       \
        HF_ERROR("Assertion %s failed in file %s line %d\n", #x, __FILE__, __LINE__) \
}

class HFIO 
{
public:
    HFIO();
    HFIO(const HFIO& orig);
    virtual ~HFIO();

    void set_loglevel(EMessageType level);
    EMessageType get_loglevel() const;

    void message(EMessageType prio, const char *file, int32_t line,
                 const char *fmt, ...) const;
    
    
protected:
    const char* get_msg_intro(EMessageType prio) const;
    
    FILE *target;
    bool show_file_and_line;
    bool syntax_highlight;
    EMessageType loglevel;
    
    static const EMessageType levels[NUM_LOG_LEVELS];
    static const char *message_strings[NUM_LOG_LEVELS];
    static const char *message_strings_highlight[NUM_LOG_LEVELS];
};


}
#endif	/* IO_HFIO_H */
