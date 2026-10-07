#include <pthread.h> // For threads.
#include <unistd.h> // ???

#ifdef _WIN32 
#define EXPORT __declspec(dllexport) 
#else 
#define EXPORT __attribute__((visibility("default"))) 
#endif

// Audio
typedef struct {
    int playing;
    int phase;
    int period;
    short amp;
} ToneState;

typedef struct MicroController{
    int activated;

    int led_data;
    int switch_data;
    int button_data;

    int rgb_led_r;
    int rgb_led_g;
    int rgb_led_b;

    char ssd_data[2];

    int display_data[80]; //x pos, y position are bits of int.
    
    ToneState *buzzer_pointer;
    int buzzer_freq;
} MicroController;


