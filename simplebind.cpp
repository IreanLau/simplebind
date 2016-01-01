//#include <iostream>
//using namespace std;
//
//// 占位符类型对象
//namespace
//{
//	class placeholder {};
//	placeholder _1;
//	placeholder _2;
//	placeholder _3;
//	placeholder _4;
//	placeholder _5;
//	placeholder _6;
//
//}
//
///////////////////////////////////////////////////////////////////
//// 1:简单模拟绑定一般函数
//
////template <typename R, typename Arg>
////class simple_bind_t
////{
////	typedef R (*fn)( Arg);
////	fn fn_ ;
////
////public :
////	simple_bind_t(fn f): fn_(f ){}
////
////	R operator ()(Arg a)
////	{
////		return (*fn_ )(a);
////	}
////};
////
////// 构造的仿函数对象的模板函数
////template <typename R, typename Arg >
////simple_bind_t <R, Arg> simple_bind (R(* fn)(Arg ), const placeholder &)
////{
////	return simple_bind_t <R, Arg>(fn );
////}
////
////void func (int i)
////{
////	cout<<"func()->" <<i<< endl;
////}
////
////void Test1 ()
////{
////	simple_bind(func , _1)(10);
////}
//
///////////////////////////////////////////////////////////////////
//// 2:简单模拟绑定成员函数
//
//// 绑定仿函数模板类
//template <typename R, typename T, typename Arg >
//class simple_bind_t
//{
//	typedef R(T::* fn)(Arg);
//	fn fn_;
//	T t_;
//public:
//	simple_bind_t(fn f, const T & t) : fn_(f), t_(t) {}
//
//	R operator ()(Arg a)
//	{
//		return (t_.*fn_)(a);
//	}
//};
//
//// 构造的仿函数对象的模板函数
//template <typename R, typename T, typename Arg >
//simple_bind_t <R, T, Arg > simple_bind(R(T ::*fn)(Arg), const T & t, const placeholder &)
//{
//	return simple_bind_t <R, T, Arg >(fn, t);
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
//void Test2()
//{
//	AA a;
//	simple_bind(&AA::func, a, _1)(10);
//}
//
//int main()
//{
//	//Test1();
//	Test2();
//
//	return 0;
//}
