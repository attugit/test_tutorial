Circular buffer

Make tests and implementation of fixed sized end-to-end connected circular buffer.
Each push back should up to fixed size limit should add new element to buffer.
Every next push back should overwrite oldest data.

```
template <typename T, std::size_t Limit>
struct circular_buffer {
  void push_back(T cosnt&);
  T const& operator[](std::size_t) const;
};
```
