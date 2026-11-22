# Node (`node.c`, `node.h`)

Модуль системы дерева из узлов. Работает на основе ленивого дерева.

Определения:
- `NODE_DEFAULT_CHILDREN_COUNT` `32` - Количество дочерних узлов по умолчанию.

Структура:
```c
struct Node {
    Node *parent;           // Родительский узел.
    Array *children;        // Дочерние узлы.
    Vec3d position;         // Позиция узла.
    versor quaternion;      // Поворот узла.
    Vec3d scale;            // Масштаб узла.
    mat4 transform;         // Матрица локальной трансформации узла.
    mat4 result_transform;  // Итоговая матрица с учетом родительской трансформации.
    bool changed;           // Флаг необходимости пересчета матрицы трансформации.
    bool parent_changed;    // Флаг указывающий на изменения в родительском узле.
};
```

Функции:
- `Node* Node_create(Node *parent)` - Создать нод.
- `void Node_destroy(Node **node)` - Уничтожить нод.
- `Array* Node_get_children(Node *self)` - Получить список дочерних нод.
- `void Node_set_position(Node *self, Vec3d position)` - Установить позицию.
- `void Node_set_quaternion(Node *self, versor quaternion)` - Установить поворот.
- `void Node_set_scale(Node *self, Vec3d scale)` - Установить масштаб.
- `void Node_rotate(Node *self, Vec3d axis, float angle)` - Вращать узел.
- `void Node_get_transform(Node *self, mat4 dest)` - Получить матрицу трансформации.
- `Vec3d Node_get_world_position(Node *self)` - Получить позицию в мире.
- `void Node_get_world_quaternion(Node *self, versor dest)` - Получить поворот в мире.
- `Vec3d Node_get_world_scale(Node *self)` - Получить масштаб в мире.
- `Node* Node_copy(Node *self, Node *parent)` - Копировать нод c потомками в переданный родитель.
- `void Node_remove_child(Node *self, Node *child)` - Удалить дочерний узел (из списка потомков).
- `void Node_set_parent(Node *self, Node *parent)` - Установить родителя.
- `Node* Node_get_parent(Node *self)` - Получить родителя.
- `void Node_recalculate_matrix(Node *self)` - Пересчитать матрицу трансформации.
- `void Node_invalidate_parent(Node *self)` - Проход потомков в глубину с изменением флага parent_changed.
- `size_t Node_count_nodes(Node *self)` - Получить количество узлов в узле.
- `size_t Node_count_all_nodes(Node *self)` - Количество узлов во всем дереве.
