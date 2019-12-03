# ShortString

ShortString은 성능최적화를 위해 std::string을 대처하기 위해 설계되었습니다.

C++에서 std::string은 문자열에 관련된 라이브러리입니다.
표준 라이브러리이기에 문자가 사용되는 곳이라면 이 std::string은 빈번히 사용되고 있습니다.

하지만 std::string은 성능에 악영향을 미칠 수 있습니다. 그 이유는 std::strintg은 메모리 동적할당을 요구하기 때문입니다. std::string 객체를 하나 선언하는 것만으로도 동적할당은 발생합니다. 이게 얼마나 큰 문제가 되는지 한번 살펴보도록 하겠습니다. 아래 코드는 단순히 숫자하나는 std::string으로 변환하는 작업을 합니다. 

```cpp
void main()
{
    int i(7);
    std::ostringstream os;
    os << i;
    std::string s = os.str();
 
    std::cout << _gCountAlloc << std::endl;
}
```

이 코드에서는 약 **40번**의 메모리 동적할당을 실행합니다. 동적할당 한번에 1000줄 이상의 코드가 실행된다는 점을 감안하면 실행되는 작업에 비해 매우 비효율적인 일들이 진행됩니다.
