# Operator Overloading
- Nạp chồng toán tử (Operator Overloading) là việc định nghĩa lại cách hoạt động của các toán tử (+, -, =, ==, <<, >>,...) cho các kiểu dữ liệu do người dùng định nghĩa (class/struct).
- Cú pháp:
```cpp
<return_type> operator symbol (parameter)
{
    // logic của toán tử
}
```

## Các toán tử có thể định nghĩa lại:
```
+	–	*	/	%	^	&	|	~	!	=	<	>	+=	-=	*=
/=	%=	^=	&=	|=	<<	>>	>>=		<<=	==	!=	<=	>=	&&	||	++
—	->*	,	->	[]	()	new	delete	new[]	delete[]
```
### Các toán tử không thể định nghĩa lại:
Toán tử . (chấm)
Toán tử phạm vi ::
Toán tử điều kiện ?:
Toán tử sizeof


# Từ khóa const