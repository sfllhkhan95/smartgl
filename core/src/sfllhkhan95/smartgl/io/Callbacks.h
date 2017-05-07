#pragma once

void Display();
void ReshapeGL(int, int);

void KeyboardEvents(unsigned char, int, int);
void KeyboardUpEvents(unsigned char, int, int);
void KeyboardSpecialEvents(int, int, int);
void KeyboardSpecialUpEvents(int, int, int);

void MouseEvents(int, int, int, int);
void PassiveMotionEvents(int, int);
void ActiveMotionEvents(int, int);

void TimerGL(int);
void IdleGL();