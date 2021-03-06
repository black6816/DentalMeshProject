

#ifndef CGAL_MIN_MAX_N_H
#define CGAL_MIN_MAX_N_H

#include <igit_geometry/result_of_.h>

#include <igit_geometry/number_type_basic_.h>
#ifndef CGAL_KERNEL_INLINE
#  define CGAL_KERNEL_INLINE inline
#endif

#ifndef CGAL_KERNEL_MEDIUM_INLINE
#  define CGAL_KERNEL_MEDIUM_INLINE
#endif

#ifndef CGAL_KERNEL_LARGE_INLINE
#  define CGAL_KERNEL_LARGE_INLINE
#endif
#include<igit_geometry/Object_.h>


namespace CGAL {

// min_n() and max_n() functions similar to std::min() and std::max(),
// but which allow more than 2 arguments.
// Hopefully the next standard will have a variadic version of them.

// Currently implemented for up to 8 arguments.
// TODO : to be documented (or wait for the next standard to have it?)

template < typename T > inline
const T&
min_n(const T& t0, const T& t1)
{ return (std::min)(t0, t1); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2)
{ return (std::min)(t0, (std::min)(t1, t2)); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2, const T& t3)
{ return (std::min)(t0, min_n(t1, t2, t3)); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4)
{ return (std::min)(t0, min_n(t1, t2, t3, t4)); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5)
{ return (std::min)(t0, min_n(t1, t2, t3, t4, t5)); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5, const T& t6)
{ return (std::min)(t0, min_n(t1, t2, t3, t4, t5, t6)); }

template < typename T > inline
const T&
min_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5, const T& t6, const T& t7)
{ return (std::min)(t0, min_n(t1, t2, t3, t4, t5, t6, t7)); }


template<typename T> inline
const T&
max_n(const T& t) { return t; }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1)
{ return (std::max)(t0, t1); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2)
{ return (std::max)(t0, (std::max)(t1, t2)); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2, const T& t3)
{ return (std::max)(t0, max_n(t1, t2, t3)); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4)
{ return (std::max)(t0, max_n(t1, t2, t3, t4)); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5)
{ return (std::max)(t0, max_n(t1, t2, t3, t4, t5)); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5, const T& t6)
{ return (std::max)(t0, max_n(t1, t2, t3, t4, t5, t6)); }

template < typename T > inline
const T&
max_n(const T& t0, const T& t1, const T& t2, const T& t3, const T& t4,
      const T& t5, const T& t6, const T& t7)
{ return (std::max)(t0, max_n(t1, t2, t3, t4, t5, t6, t7)); }

} //namespace CGAL

#endif // CGAL_MIN_MAX_N_H
