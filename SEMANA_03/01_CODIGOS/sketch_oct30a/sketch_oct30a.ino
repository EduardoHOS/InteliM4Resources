/* Define pin numbers for LEDs and buttons: */
const uint8_t buttonPins[] = {34, 35, 32, 33};
const uint8_t ledPins[] = {19, 18, 17, 16};

#define MAX_GAME_LENGTH 4

/* Global variables - store the game state */
uint8_t gameSequence[MAX_GAME_LENGTH] = {0};
uint8_t gameIndex = 0;
uint8_t sequenceCount = 0;

bool inPlayerTurn = false;
bool gameInProgress = false;

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(13, INPUT_PULLUP); // Start button

  // The following line primes the random number generator.
  // It assumes a floating pin (disconnected):
  randomSeed(analogRead(4));
}

void displayScore() {
  // Your display score code here
}

void lightLed(byte ledIndex, int duration =300) {
  digitalWrite(ledPins[ledIndex], HIGH);
  delay(duration);
  digitalWrite(ledPins[ledIndex], LOW);
}

void playSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte currentLed = gameSequence[i];
    lightLed(currentLed, 500); // level up the duration 
    delay(100);
  }
  inPlayerTurn = true;
}

byte readButtons() {
  while (true) {
    for (byte i = 0; i < 4; i++) {
      byte buttonPin = buttonPins[i];
      if (digitalRead(buttonPin) == LOW) {
        return i;
      }
    }
    delay(1);
  }
}

void gameOver() {
  for (int i = 0; i < 4; i++){
    lightLed(i, 100);
  }
  // Your game over code here
  sequenceCount = 0;
  gameInProgress = false;
  gameIndex = 0; // Turn to 0 the number of plays 
}

bool checkUserSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte expectedButton = gameSequence[i];
    byte actualButton = readButtons();
    lightLed(actualButton);
    if (expectedButton != actualButton) {
      return false;
    }
  }
  return true;
}

void playLevelUpSound() {
  // Your level up sound code here
}

void loop() {
  if (digitalRead(13) == LOW && !gameInProgress) {
    gameInProgress = true;
    sequenceCount = 0;
 // turn to 0 when it stars 
  }

  if (gameInProgress) {
      gameSequence[gameIndex] = random(0, 4);
      gameIndex++;
      if (gameIndex > MAX_GAME_LENGTH){
         gameOver();
       } 
      playSequence();
      if (!checkUserSequence()) {
        gameOver();
      }
    }
}
