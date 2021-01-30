byte counter = 0;
byte colorIndex = 0;

Color colors[6] = {
    RED,
    YELLOW,
    GREEN,
    BLUE,
    WHITE,
    OFF,
};

Timer nextStep;

void setup() {}

void loop()
{

  if (buttonPressed())
  {
    counter++;
    if (counter >= 6)
    {
      counter = 0;
    }
  }

  if (nextStep.isExpired())
  {
    setColor(colors[colorIndex]);

    FOREACH_FACE(face)
    {
      if (counter == 0 && colorIndex == 0 && face == 0)
      {
        setColorOnFace(dim(colors[colorIndex], 0), face);
      }
      else if (counter == 1 && colorIndex == 1 && face % 3 == 0)
      {
        setColorOnFace(dim(colors[colorIndex], 47), face);
      }
      else if (counter == 2 && colorIndex == 2 && face % 2 == 0)
      {
        setColorOnFace(dim(colors[colorIndex], 47), face);
      }
      else if (counter == 3 && colorIndex == 3 && face % 3 != 0)
      {
        setColorOnFace(dim(colors[colorIndex], 95), face);
      }
      else if (counter == 4 && colorIndex == 4 && face != 5)
      {
        setColorOnFace(dim(colors[colorIndex], 95), face);
      }
    }

    colorIndex++;
    if (colorIndex >= 5)
    {
      colorIndex = 0;
    }

    nextStep.set(500);
  }
}
