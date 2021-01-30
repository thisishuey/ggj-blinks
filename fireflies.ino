#define COLOR_CHANGE_DURATION 500
#define NUMBER_OF_COLORS 3

byte colorIndex = 0;
byte colorStep = 0;
byte numberIndex = 0;
Timer nextStep;

Color colors[NUMBER_OF_COLORS] = {
    RED,
    GREEN,
    BLUE,
};

void setup()
{
  randomize();
  colorIndex = random(NUMBER_OF_COLORS - 1);
  numberIndex = random(NUMBER_OF_COLORS - 1);
}

void loop()
{
  if (buttonPressed())
  {
    colorIndex = random(NUMBER_OF_COLORS - 1);
    numberIndex = random(NUMBER_OF_COLORS - 1);
  }

  if (nextStep.isExpired())
  {
    setColor(colors[colorStep]);

    FOREACH_FACE(face)
    {
      if (colorStep == colorIndex && ((numberIndex == 0 && face == 0) ||
                                      (numberIndex == 1 && face % 3 == 0) ||
                                      (numberIndex == 2 && face % 2 == 0)))
      {
        setColorOnFace(dim(colors[colorIndex], 63), face);
      }
    }

    colorStep++;
    if (colorStep >= NUMBER_OF_COLORS)
    {
      colorStep = 0;
    }

    nextStep.set(COLOR_CHANGE_DURATION);
  }
}
