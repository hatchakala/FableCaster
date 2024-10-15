#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const char *story =
    "Once upon a time in a faraway land, there was a young princess who loved to explore the world on her magical horse. "
    "One day, she found a hidden forest full of magical trees that glowed at night. Her adventures had only just begun!";

void displayText(int startIdx)
{
  lcd.clear();

  lcd.setCursor(0, 0);
  for (int i = startIdx; i < startIdx + 16 && story[i] != '\0'; i++)
  {
    lcd.print(story[i]);
  }

  lcd.setCursor(0, 1);
  for (int i = startIdx + 16; i < startIdx + 32 && story[i] != '\0'; i++)
  {
    lcd.print(story[i]);
  }
}

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  int storyLength = strlen(story);

  // scroll = 32 chars (both lines - 16 each)
  for (int i = 0; i < storyLength; i += 32)
  {
    displayText(i);
    delay(3000); // wait for 3 sec
  }
}
