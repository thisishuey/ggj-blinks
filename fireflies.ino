const int duration = 500;
const byte numberOfColors = 3;

byte colorIndex = 0;
byte colorStep = 0;
byte numberIndex = 0;
Timer nextStep;

Color colors[numberOfColors] = {
    RED,
    GREEN,
    BLUE,
};

void setup()
{
  randomize();
  colorIndex = random(numberOfColors - 1);
  numberIndex = random(numberOfColors - 1);
}

void loop()
{
  if (buttonPressed())
  {
    colorIndex = random(numberOfColors - 1);
    numberIndex = random(numberOfColors - 1);
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
        setColorOnFace(dim(OFF, 0), face);
      }
    }

    colorStep++;
    if (colorStep >= numberOfColors)
    {
      colorStep = 0;
    }

    nextStep.set(duration);
  }
}
