# lab1_list
Задачей является реализация односвязного списка с дополнительной функцией reverse().
	Класс реализован на C++ в качестве входных значений используется тип данных int.
	Класс List с приватным классом Node в котором хранятся значения (data), указатель (Next) и размер (Size).

1. void push_back
	Если Head пустая, то создаем новый элемент списка, иначе проходимся по списку пока не найдем элемент у которого указатель nullptr и добавляем новый элемент. Увеличиваем размер.
2. void push_front
         Создаем новый элемент списка, ставим указатель головы на этот элемент. Увеличиваем размер списка на единицу. 	
3. void pop_back
	С помощью remove убираем элемент с индексом равным size-1
4. void pop_front()
	Изначальная Head помещается во временную переменную, следующий элемент - новая Head
5. void insert
Ищем элемент с индексом на единицу меньше нужного. Присваиваем значение указателя на место в памяти у нового элемента к элементу с введенным индексом. Связывает новый элемент и предыдущий элемент. Увеличиваем размер списка
6. int at
	Проходимся по списку до нужного элемента и выводи значения index.
7. void remove
	Если индекс 0, то просто добавляем в начало списка значение с помощь pop_front, а если 1, то ищем элемент с индексом на единицу меньше нужного у этого элемента ставим указатель через элемент. Удаляем указатели и информацию у искомого элемента.Уменьшаем размер списка.
8. get_size
Получение размера списка
9. void clear()
	Удаляем первый элемент с помощью pop_front до тех пор пока Size не станет равным 0.
10. void set
Проходимся по списку пока не находим индекс нужного элемента, заменяем значение на новое.
11. bool isEmpty()
	Если список пуст (указатель на Head = nullptr), то выводим 0 иначе 1.
12. Перегрузка оператора вывода <<
	Приводим вывод списка к виду [N1;N2;....] путем создания копии списка в который помещаем значения оригинального списка между которыми ставим “;” ,если значение не последние. Если значение последние выводим “]”.
13. void reverse()
         Проходим по списку меняя два соседних элемента до тех пор пока последний элемент не станет первым.
