# note
## ex00
- ``` std::cout << std::fixed << std::setprecision(3) << "float_test: " << 4.0 << "f" << std::endl; ```
	- ``` std::fixed ``` : Use fixed point format
	- ``` std::setprecision(n) ``` : Set the decimal precision to be used to format floating-point values on output operations (入出力ストリームで浮動小数点型の桁数を指定出来るマニピュレータ)
- ``` str.find('.') != string::npos ```
	- If found, it returns its position.
	- If not found, it returns ``` string::npos ```.
	- npos means "no posiont" or "not found".
- ``` strtol(str.c_str(), &end, 10); ```
	- ``` str.c_str() ``` : returns the contents of the C++ std::string as a C-style string (const char*), which strtol requires.
	- &end: It allows strtol to modify end and make it point to the first character that was not converted.
	```
	char *end;
	long value = strtol("123abc", &end, 10);
	value = 123
	end points to "abc"
	```

```
errno = 0;
long value_int = strtol(str.c_str(), &end, 10);
if (errno == ERANGE || ...)
```

1. errno = 0: reset any previous error
2. strtol attempts the conversion
3. If the number is too large or too small for a long, strtol sets: ``` errno = ERANGE; ```
