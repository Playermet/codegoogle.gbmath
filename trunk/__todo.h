/** \file
 \brief TODO  doc (RUS)

 
 
 \brief для точки 2д  добавить трансформацию и процее. 
 \brief  (ДЛЯ ЛУЧА)
	   \todo Сделать перечечения: луч, сфера, бокс, плоскость,
	  \todo   bool checkIntersectRay(const ray3d& ray) {....}
	  \todo   bool checkIntersecеSphere(const Sphere& sph) {....}
	  \todo  bool checkIntersectAABB(const aabb& aabb) {....}
	  \todo  bool checkIntersectPlane(const Plane& aabb) {....}
	   так же поправить  и комменты
  
 \brief    для ray2d добавить
  			// bool checkIntersectCircle(const CIrcle& c)
			// bool checkIntersectRect(const Rect& r)
			// bool checkIntersectRectContactPnts(const Rect& r)
			// bool checkIntersectLine
  
 
 \brief Quaternion поправить оттестировать добавить методов
 \brief для Rect добавить методов   void move(const Normal2& normal, float distance) { } 
 \brief можно зачести свой класс исключений
 \brief определиться кидает ли mat44::invert исключение и поправить код
 \todo оставить только один матр. стек.
 \todo внести собственно найденные асм-функции из лабиринта
 \todo поправить Geometric context
 \brief для normal2 и normal3 добавить соотв. методы для них
 \brief для 2-х мерных добавить всё из платфомер кода
 \todo Поправить проверить что все классы в forward decl 
 \todo  удалить все assert(false) и проверить все, что за ними помечено 
 \todo  add func random() 
 \todo добавить pop_point для прямоугольника из лабиринта. Добавить и для 3д аналог 
 \todo класс drawer подкорректировать удалить из него матрицы, написать тест
 \todo  лишние файлы/классы  для цвета  удалить
 \todo  поправить и удалить комменты color3f.h
 \todo  ВСЕ ШАБЛОНЫ УДАЛИТЬ.  особенно в цветах.
 \todo  В описание добавить, что либа без шаблонов
 
 \todo  delete all print()
 \todo add all operators >> << to from string
 \todo  Поменять ассерты на исключения  
 \todo  Поправить операторы для сравнения по эпсилону.
 \todo  Перенести в cpp методы матрицы 4x4 .
 \todo  Тяжелые методы матриц перенести в cpp
 \todo  удалить собственные #ifdef XXXXXX
 \todo  Поправить макрозащиту на типы RECT и POINT
 \todo добавить камеры: fp, mv, target и из примера D3D9NormalMapping

 //!   \todo Написать для circle построение внутреннего и внешнего прямоуголника.
 
 //    ---------------- CIRCLE ------------
// TODO: bool CIRCLE::checkIntersectCircle(const Circle& c) const {...}
// TODO: boolCIRCLE:: checkIntersectRect(const Rect& r) const {...}

// TODO:  3d::Sphere CIRCLE::toObjectSphere(VP& vp, )

// bool checkIntersectContactPoints(vec2& outp1, vec2& outp2, const Circle& c) {...}
// http://algolist.manual.ru/maths/geom/intersect/circlecircle2d.php







*/



