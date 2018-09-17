/*
  SineStepperController library
  Author: T-Kuhn.
  Sapporo, October, 2018. Released into the public domain.
  */

#ifndef SineStepperController_h
#define SineStepperController_h

#include "Constants.h"
#include "Arduino.h"
#include "SineStepper.h"
#include "Queue.h"
#include "MoveBatch.h"

class SineStepperController
{
public:
  SineStepperController(double freq);
  void update();
  void attach(SineStepper *sStepper);
  void addMoveBatch(MoveBatch mb);
  MoveBatch popMoveBatch();
  MoveBatch peekMoveBatch();

private:
  bool _isExecutingBatch;
  uint32_t _counter = 0;
  Queue<MoveBatch> _batchQueue = Queue<MoveBatch>(MAX_NUM_OF_BATCHED_MOVES);
  SineStepper *_sineSteppers[MAX_NUM_OF_STEPPERS];
  double _frequency;
};

#endif
