# C Notes

## C PreProcessor

* [C Define PreProcessor]
* [C IfDef/EndIf]

```c
#define YEARS_OLD 6

function potentiometer() {
  // macros do not need to be unindented
  #ifdef YEARS_OLD
    Serial.print("Augustus Corgan is over %d years old.\n", YEARS_OLD);
  #endif
}
```

[C Define PreProcessor]: https://www.geeksforgeeks.org/c-define-preprocessor/
[C IfDef/EndIf]: https://www.techonthenet.com/c_language/directives/ifdef.php
