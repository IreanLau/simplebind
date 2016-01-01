//namespace _mfi
//{
//
//	template<class R, class T> class dm
//	{
//	public:
//
//		typedef R const & result_type;
//		typedef T const * argument_type;
//
//	private:
//
//		typedef R(T::*F);
//		F f_;
//
//	public:
//
//		explicit dm(F f) : f_(f) {}
//
//		R & operator()(T * p) const
//		{
//			return (p->*f_);
//		}
//
//
//		R & operator()(T & t) const
//		{
//			return (t.*f_);
//		}
//
//		R const & operator()(T const & t) const
//		{
//			return (t.*f_);
//		}
//
//
//	};
//
//} // namespace _mfi
//
//
//  // unwrap
//
//template<class F> struct unwrapper
//{
//	static inline F & unwrap(F & f, long)
//	{
//		return f;
//	}
//
//	template<class R, class T> static inline _mfi::dm<R, T> unwrap(R T::* pm, int)
//	{
//		// 成员函数绑定的仿函数对象
//		return _mfi::dm<R, T>(pm);
//	}
//};
//
//template< class A1, class A2 > class list2 : private storage2< A1, A2 >
//{
//private:
//
//	typedef storage2< A1, A2 > base_type;
//
//public:
//
//	list2(A1 a1, A2 a2) : base_type(a1, a2) {}
//
//
//	template<class R, class F, class A> R operator()(type<R>, F & f, A & a, long) //A->List
//	{
//		// 装饰器模式->仿函数
//		return unwrapper<F>::unwrap(f, 0)(a[base_type::a1_], a[base_type::a2_]);
//
//		// 函数指针(实参)
//	}
//}
//
//
//// bind仿函数类
//template<class R, class F, class L> class bind_t
//{
//public:
//
//	typedef bind_t this_type;
//
//	bind_t(F f, L const & l) : f_(f), l_(l) {}
//
//#define BOOST_BIND_RETURN return
//	result_type operator()()
//	{
//		list0 a;
//		BOOST_BIND_RETURN l_(type<result_type>(), f_, a, 0);
//	}
//
//	template<class A1> result_type operator()(A1 & a1)
//	{
//		list1<A1 &> a(a1);
//		BOOST_BIND_RETURN l_(type<result_type>(), f_, a, 0);
//	}
//#undef BOOST_BIND_RETURN
//
//};
//
//#define BOOST_BIND bind
//
//// bind模板函数
//template<class R, class T, class A1>
//_bi::bind_t< R, _mfi::dm<R, T>, typename _bi::list_av_1<A1>::type >
//BOOST_BIND(R T::*f, A1 a1)
//{
//	typedef _mfi::dm<R, T> F;
//	typedef typename _bi::list_av_1<A1>::type list_type;
//	return _bi::bind_t<R, F, list_type>(F(f), list_type(a1));
//}
//
//void f1(int i)
//{
//	cout << "f1()->" << i << endl;
//}
//
//class AA
//{
//public:
//	void func(int i)
//	{
//		cout << "AA::func()->" << i << endl;
//	}
//};
//
////void Test1()
////{
////	//bind(f1, i) (10);
////
////	AA aa;
////	bind(&AA::func, &aa, _1) (10);
////}