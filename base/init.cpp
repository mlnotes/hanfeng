#include "init.h"
#include "../io/HFIO.h"

namespace hanfeng
{
    HFIO *hf_io = NULL;
    
    void (*hf_print_message)(FILE *target, const char *str) = NULL;
    void (*hf_print_warning)(FILE *target, const char *str) = NULL;
    void (*hf_print_error)(FILE *target, const char *str) = NULL;
    void (*hf_cancel_computations)(bool &delayed, bool &immediately) = NULL;

    void init_hanfeng(
                void (*print_message)(FILE *target, const char *str),
                void (*print_warning)(FILE *target, const char *str),
                void (*print_error)(FILE *target, const char *str),
                void (*cancel_computations)(bool &delayed, bool &immediately))
    {
        if(!hf_io)
            hf_io = new HFIO();
        
        hf_print_message = print_message;
        hf_print_warning = print_warning;
        hf_print_error = print_error;
        hf_cancel_computations = cancel_computations;
    }
    
    void exit_hanfeng()
    {
        hf_print_message = NULL;
        hf_print_warning = NULL;
        hf_print_error = NULL;
        hf_cancel_computations = NULL;
    }
}