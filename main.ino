#include "Particle.h"


// Pin Definitions
#define LED D7 

// Handler definition
void handler(char const *name, char const *data);


void setup() {
    pinMode(LED, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handler, ALL_DEVICES);
}

void loop() {

}

void handler(char const *name, char const *data) {
    std::string newData = std::string(data);
    if (newData == "wave")
    {
        for (int i = 0; i < 3; i++)
        {
            digitalWrite(LED, HIGH);
            delay(100);
            digitalWrite(LED, LOW);
            delay(100);
        }
    }
    else if (newData == "pat")
    {
        for (int i = 0; i < 5; i++)
        {
            digitalWrite(LED, HIGH);
            delay(100);
            digitalWrite(LED, LOW);
            delay(500);
        }
    }
}
