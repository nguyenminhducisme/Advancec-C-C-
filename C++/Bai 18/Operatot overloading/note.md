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

<table border="1" cellspacing="0" cellpadding="8" style="border-collapse: collapse; text-align: center;">
  <tr>
    <td>+</td> <td>-</td> <td>*</td> <td>/</td> <td>%</td> <td>^</td> <td>&</td> <td>|</td>
  </tr>
  <tr>
    <td>~</td> <td>!</td> <td>=</td> <td><</td> <td>></td> <td>+=</td> <td>-=</td> <td>*=</td>
  </tr>
  <tr>
    <td>/=</td> <td>%=</td> <td>^=</td> <td>&=</td> <td>|=</td> <td>&lt;&lt;</td> <td>&gt;&gt;</td> <td>&gt;&gt;=</td>
  </tr>
  <tr>
    <td>&lt;&lt;=</td> <td>==</td> <td>!=</td> <td>&lt;=</td> <td>&gt;=</td> <td>&&</td> <td>||</td> <td>++</td>
  </tr>
  <tr>
    <td>--</td> <td>-&gt;*</td> <td>,</td> <td>-&gt;</td> <td>[]</td> <td>()</td> <td>new</td> <td>delete</td>
  </tr>
  <tr>
    <td>new[]</td> <td>delete[]</td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
  </tr>
</table>



### Các toán tử không thể định nghĩa lại:
 - Toán tử . (chấm)
 - Toán tử phạm vi ::
 - Toán tử điều kiện ?:
 - Toán tử sizeof


# Từ khóa const