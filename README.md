# lab4_translator
Это простой арифметический транслятор.
На данный момент поддерживаеся целочисленные и вещественные типы операндов, скобки,
а также операции `+, -, *, /` (в том числе унарный минус).
Для задания вещественных типов поддерживаются
следущие типы задания: `0.1`, `0.0`, `1.`, `1.0`
(количество нулей в каждом из этих примеров может быть любым).
При вводе строки можно использовать пробелы.

|Input|Output|
|---|---|
|1+2|10|
|1.+5.2|6.2|
|000.00+100.00|100|
|3*(2+1)|9|
|-1+2|1|
|15    + 23</pre>|38|
|(-1+1)/0|Caught an exception: cant divide by 0|
|(2+1|String analyze spotted incorrect expression|
||Caught an exception: empty string|
