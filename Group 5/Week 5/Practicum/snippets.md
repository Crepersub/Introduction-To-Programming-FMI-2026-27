**1.** Какво ще отпечата на екрана следният код?
```cpp
#include <iostream>
using namespace std;

int main()
{
    unsigned int first = 10;
    unsigned int second = 10;

    while (cout << first << endl, ----first);

    while (cout << second << endl, second----);
}
```
<details>
    <summary>Обяснение</summary>
<b>Не се компилира.</b><br><br>
- Префиксното <code>--a</code> връща самата променлива (lvalue), затова върху резултата може да се приложи още едно <code>--</code>. Така <code>----first</code> е валидно и първият цикъл е наред.<br>
- Постфиксното <code>a--</code> връща само копие на старата стойност (rvalue), което не е променлива и не може да се декрементира. Затова <code>second----</code> във втория цикъл дава грешка.
</details>
<br>

**2.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int main() {
    f();
    return 0;
}

void f() {
    cout << "f()" << endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Не се компилира.</b><br><br>
Компилаторът чете отгоре надолу. Когато стигне до <code>f();</code> в <code>main()</code>, още не знае, че такава функция съществува.<br><br>
Две решения:<br>
- пишеш <code>void f();</code> (декларация) над <code>main()</code><br>
- или местиш цялата дефиниция на <code>f()</code> над <code>main()</code>
</details>
<br>

**3.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int func(int param = 10) {
    return param;
}

int main() {
    cout << func() << endl;
    cout << func(0) << endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Отпечатва 10 и 0.</b><br><br>
Когато не подадем аргумент, се взема стойността по подразбиране (10). Когато подадем аргумент, се използва той (0).
</details>
<br>

**4.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

void printCharNTimes(char c = '*', int N) {
    for (int i = 0; i < N; i++) {
        cout << c;
    }
}

int main() {
    printCharNTimes('-', 10);
    printCharNTimes(10);
}
```
<details>
    <summary>Обяснение</summary>
<b>Не се компилира.</b><br><br>
Параметрите със стойност по подразбиране трябва да са най-вдясно, след всички параметри без такава стойност. Тук <code>int N</code> е след <code>char c = '*'</code>, което не е позволено.<br><br>
Правилно е: <code>void printCharNTimes(int N, char c = '*')</code>
</details>
<br>

**5.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

int& foo() {
    int x = 42;
    return x;
}

int main() {
    int& r = foo();
    cout << r << endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Undefined Behavior.</b><br><br>
<code>x</code> е локална променлива и се унищожава, когато <code>foo()</code> завърши. Върнатата референция <code>r</code> сочи към памет, която вече не е валидна (dangling reference). Кодът се компилира, но четенето от <code>r</code> е непредсказуемо: може да излезе 42, някаква боклук стойност или програмата да се срине.
</details>
<br>

**6.** Какво ще отпечата на екрана следният код?

```cpp
int* foo() {
    int x = 42;
    return &x; 
}

int main() {
    int* p = foo();
    cout << *p << endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Undefined Behavior.</b><br><br>
Същият проблем като в №5, но с указател. <code>x</code> се унищожава след <code>foo()</code>, а <code>p</code> продължава да сочи към освободената памет (dangling pointer). Дереферирането на <code>*p</code> е непредсказуемо.
</details>
<br>

**7.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>

void setToZero(int*& p) {
    *p = 0;   
}

int main() {
    int a = 5;
    int* p = &a;
    setToZero(p);
    std::cout << a << std::endl; 
}
```
<details>
    <summary>Обяснение</summary>
<b>Отпечатва 0.</b><br><br>
<code>p</code> сочи към <code>a</code>. <code>*p = 0</code> записва 0 там, където сочи указателят, т.е. в <code>a</code>. Самият указател не се променя, така че <code>&</code> тук не е нужен, но не пречи.
</details>
<br>

**8.** Какво ще отпечата на екрана следният код?
```cpp
#include <iostream>

void setToZero(int*& p, int & b) {
    *p = 0;
    p = &b;
}

int main() {
    int a = 5;
    int b = 8;
    int* p = &a;
    setToZero(p,b);
    std::cout << a << std::endl;
    std::cout << *p << std::endl;
}

```
<details>
    <summary>Обяснение</summary>
<b>Отпечатва 0 и 8.</b><br><br>
- <code>*p = 0</code> записва 0 в <code>a</code>, защото <code>p</code> още сочи към него.<br>
- <code>p = &b</code> пренасочва указателя към <code>b</code>. Това се вижда и в <code>main()</code>, защото <code>p</code> е подаден като <code>int*&</code> (референция към указателя). С обикновен <code>int*</code> промяната щеше да остане само във функцията.<br><br>
Затова <code>a</code> е 0, а <code>*p</code> вече е <code>b</code>, т.е. 8.
</details>
<br>

**9.** Какво ще отпечата на екрана следният код?
```cpp
#include <iostream>
using namespace std;

void f(int p) { cout << p; }

void f(double p) { cout << p; }

int f(int p) { return p; }

int main() {
    f(10);
    f(10.5);
    int a = f(7);
}
```
<details>
    <summary>Обяснение</summary>
<b>Не се компилира.</b><br><br>
Претоварените функции трябва да се различават по параметрите си. Върнатият тип не се брои. <code>void f(int)</code> и <code>int f(int)</code> имат еднакви параметри, затова компилаторът не може да ги различи.<br><br>
Без третата функция кодът щеше да е валиден и да отпечата <code>1010.5</code>.
</details>
<br>

**10.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
using namespace std;

void h() { f(); }
void g() { h(); }
void f() { g(); }

int main() {
    f();
}
```
<details>
    <summary>Обяснение</summary>
<b>Не се компилира.</b><br><br>
<code>h()</code> вика <code>f()</code>, която още не е декларирана. Ако добавим <code>void f();</code> най-горе, кодът се компилира, но <code>f → g → h → f → ...</code> е безкрайна рекурсия. Всяко извикване заема място в стека, докато той се препълни (stack overflow) и програмата се срине.
</details>
<br>

**11.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
int& getValue(int& num) {
    return num; 
}


int main() {
    int x = 5;
    getValue(x) = 10;
    // x = 10;
    std::cout << "x: " << x << std::endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Отпечатва x: 10.</b><br><br>
<code>getValue</code> приема <code>x</code> по референция и връща референция към същата променлива, т.е. друго име за <code>x</code>. Резултатът е lvalue и може да му се присвоява стойност, затова <code>getValue(x) = 10</code> е същото като <code>x = 10</code> (закоментираният ред).<br><br>
Тук няма проблем с локална променлива, защото <code>x</code> живее в <code>main()</code>, а не във функцията.
</details>
<br>

**12.** Какво ще отпечата на екрана следният код?

```cpp
#include <iostream>
int& getValue(int& num) {
    return ++num;
}


int main() {
    int x = 5;
    int b = 1;
    getValue(x) = getValue(b);
    std::cout << "x: " << x << std::endl;
}
```
<details>
    <summary>Обяснение</summary>
<b>Отпечатва x: 2.</b><br><br>
<code>getValue</code> първо увеличава числото с 1, после връща референция към него.<br>
- <code>getValue(b)</code> прави <code>b</code> равно на 2 и връща <code>b</code>.<br>
- <code>getValue(x)</code> прави <code>x</code> равно на 6 и връща <code>x</code>.<br>
- Накрая на <code>x</code> се присвоява стойността на <code>b</code> (2), която презаписва 6.
</details>
