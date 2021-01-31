#define COLOR_CHANGE_DURATION 500
#define COLOR_COUNT 3
#define FACE_COUNT 5
#define NUMBER_COUNT 3

byte colorIndex = 0;
byte colorStep = 0;
bool faceDown = false;
byte faceOffset = 0;
byte numberIndex = 0;
byte numberOffset = 0;
Timer nextStep;

Color colors[COLOR_COUNT] = {
    RED,
    YELLOW,
    BLUE,
};

void setup()
{
  randomize();
}

void loop()
{
  if (buttonDoubleClicked())
  {
    faceDown = !faceDown;
  }

  if (buttonMultiClicked())
  {
    numberIndex++;
    if (numberIndex >= NUMBER_COUNT)
    {
      numberIndex = 0;
    }
  }

  if (buttonLongPressed())
  {
    colorIndex++;
    if (colorIndex >= COLOR_COUNT)
    {
      colorIndex = 0;
    }
  }

  if (nextStep.isExpired())
  {
    if (faceDown)
    {
      setColor(dim(GREEN, 127));
    }
    else
    {
      faceOffset = random(FACE_COUNT);
      setColor(colors[colorStep]);

      FOREACH_FACE(face)
      {
        if (colorStep == colorIndex && ((numberIndex == 0 && face == 0) ||
                                        (numberIndex == 1 && face % 3 == 0) ||
                                        (numberIndex == 2 && face % 2 == 0)))
        {
          byte adjustedFace = face + faceOffset;
          if (adjustedFace >= 6)
          {
            adjustedFace = adjustedFace - 6;
          }
          setColorOnFace(dim(colors[colorIndex], 0), adjustedFace);
        }
      }

      colorStep++;
      if (colorStep >= COLOR_COUNT)
      {
        colorStep = 0;
      }
    }

    nextStep.set(COLOR_CHANGE_DURATION);
  }
}
