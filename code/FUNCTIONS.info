////////////////////////////////////////////
// checks if it's greater than maximum value or less than then the minimum value
int clipValue(int in, int minVal, int maxVal) {

  int out;

  minVal++;

  if (in > maxVal) {
    out = maxVal;
  }
  else if (in < minVal) {
    out = minVal -1;
  }
  else {
    out = in;
  }

  return out;
}

float lerp(float x1, float x2, float ratio) {
  return x1 + (x2 - x1) * ratio;
}
