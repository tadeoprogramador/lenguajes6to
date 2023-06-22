#define BUTTON_PIN 4
#define LED_PIN 12
#define DEBOUNCE_TIME 40

uint32_t tiempo_actual = 0;

typedef enum {
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RISING
}debounceState_t;


debounceState_t currentState;

void buttonPtressed (void);
void buttoRealeased (void);
void debounceFSM_init(void);
void debounceFSM_update (void);

void setup() {
  pinMode (LED_PIN, OUTPUT);
  pinMode (BUTTON_PIN, INPUT);
  debounceFSM_init();
  tiempo_actual = millis();
}

void loop() {
  debounceFSM_update();
}

void debounceFSM_init(void) {
  currentState = BUTTON_UP;
}

void debounceFSM_update(void) {
  switch (currentState) {
    case BUTTON_UP:
      if (!(digitalRead(BUTTON_PIN))){
        currentState = BUTTON_FALLING;
      }else currentState = BUTTON_UP;
  	break;
    
  	case BUTTON_FALLING:
  	  if (millis() - tiempo_actual >= DEBOUNCE_TIME){
        if (!digitalRead(BUTTON_PIN)){
          buttonPressed();
          currentState = BUTTON_DOWN;
        }else currentState = BUTTON_UP;
      }
    break;
    
    case BUTTON_DOWN:
      if (digitalRead(BUTTON_PIN)) currentState = BUTTON_RISING;
    break;
              
    case BUTTON_RISING:
      if (millis() - tiempo_actual >= DEBOUNCE_TIME){
        if (digitalRead (BUTTON_PIN)){
          buttonReleased();
          currentState = BUTTON_UP;
        }else currentState = BUTTON_DOWN;
      }
    break;
  }
}                

void buttonPressed(void){
	digitalWrite (LED_PIN, HIGH);
}

void buttonReleased(void){
	digitalWrite (LED_PIN, LOW);
}
                  
            