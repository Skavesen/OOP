#pragma once

int getChoice(const char* prompt, int variantsCount, ...);

int getChoice(Message prompt, int variantsCount, ...);

bool confirm(const char* prompt);

bool getValue(const char* prompt, int& value);

bool getValue(const char* prompt, unsigned int& value);

bool getValue(const char* prompt, float& value);

bool getValue(const char* prompt, char* value);

bool checkAccess(const char* password, int tryCount = 3);
