// #include "array.h"

// template <Arrayable T>
// Array<T>::Array(): _size{0}, arr{nullptr}
// {}

// template <Arrayable T>
// void Array<T>::resize(size_t new_size)
// {
//     _size = new_size;
//     std::shared_ptr<T[]> tmp = std::make_shared<T[]>(new T[_size]);
//     for (size_t i{0}; i < _size; ++i)
//     {
//         tmp[i] = arr[i];
//     }
//     arr = std::move(tmp);
// }

// template <Arrayable T>
// size_t Array<T>::size()
// {
//     return _size;
// }

// template <Arrayable T>
// void Array<T>::push(T fig)
// {
//     resize(_size + 1);
//     arr[_size] = fig;
// }

// template <Arrayable T>
// void Array<T>::remove(size_t index)
// {
//     if (_size = 0) throw std::invalid_argument("Array is empty");
//     if (index < 0 || index > _size) throw std::invalid_argument("Index out of range");
//     _size = _size - 1;
//     std::shared_ptr<T[]> tmp = std::make_shared<T[]>(new T[_size]);
//     arr[index] = nullptr;
//     for (size_t i{0}; i < _size; ++i)
//     {
//         if (arr[i] == nullptr) continue;
//         tmp[i] = arr[i];
//     }
//     arr = std::move(tmp);
// }

// template <Arrayable T>
// T& Array<T>::operator[](size_t index)
// {
//     if (index < 0 || index > _size) throw std::invalid_argument("Index out of range");
//     return arr[index];
// }