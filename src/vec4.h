#include <array>

class vec4 { 
	public:
		static const int e = 4;
		std::array <float, 4> d;
		
		//Any possible constructors i can think of
		inline vec4::vec4 () { vec4 ( 0.0 ); }
		inline vec4::vec4 ( float a, float b, float c ) { d[0] = a; d[1] = b; d[2] = c; }
		inline vec4::vec4 ( float a, float b, float c, float d )	 { d[0] = a; d[1] = b; d[2] = c; d[3] = d; }
		inline vec4::vec4 ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) d[i] = a;
		}
		inline vec4::vec4 ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] = a.d[i];
		}
		
		//Getter operator
		inline float & vec4::operator[] ( unsigned int i ) { return d[i]; }
		inline float vec4::operator[] ( unsigned int i ) const { return d[i]; }
		
		//Get and set x,y,z,w
		inline float	vec4::x () const		{ return d[0]; }
		inline float	vec4::y () const		{ return d[1]; }
		inline float	vec4::z () const		{ return d[2]; }
		inline float	vec4::w () const		{ return d[3]; }
		inline void	vec4::s_x ( float a )	{ d[0] = a; }
		inline void	vec4::s_y ( float a )	{ d[1] = a; }
		inline void	vec4::s_z ( float a )	{ d[2] = a; }
		inline void	vec4::s_w ( float a )	{ d[3] = a; }
		
		//Get and set r,g,b,a
		inline float	vec4::r () const		{ return d[0]; }
		inline float	vec4::g () const		{ return d[1]; }
		inline float	vec4::b () const		{ return d[2]; }
		inline float	vec4::a () const		{ return d[3]; }
		inline void	vec4::s_r(  float a )	{ d[0] = a; }
		inline void	vec4::s_g ( float a )	{ d[1] = a; }
		inline void	vec4::s_b ( float a )	{ d[2] = a; }
		inline void	vec4::s_a ( float a )	{ d[3] = a; }
		
		//Multiple setters
		inline vec4	 & vec4::set ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) d[i] = a;
			return (*this);
		}
		inline vec4	 & vec4::set ( float a, float b, float c ) {
			d[0] = a;
			d[1] = b;
			d[2] = c;
			return (*this);
		}
		inline vec4	 & vec4::set ( float a, float b, float c, float d ) {
			d[0] = a;
			d[1] = b;
			d[2] = c;
			d[3] = d;
			return (*this);
		}
		inline vec4	 & vec4::set ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] = a.d[i];
			return (*this);
		}
		
		//Equals operators for all valid types
		inline vec4 & vec4::operator= ( float a ) { return set(a); }
		inline vec4 & vec4::operator= ( float a, float b, float c ) { return set(a,b,c); }
		inline vec4 & vec4::operator= ( float a, float b, float c, float d ) { return set(a,b,c,d); }
		inline vec4 & vec4::operator= ( const vec4 & a ) { return set(a); }
		
		//Equality operators
		inline int vec4::operator== ( const vec4 & a ) const { 
			return (( d[0] == a.d[0] ) && ( d[1] == a.d[1] ) && ( d[2] == a.d[2] ) && ( d[3] == a.d[3] ));
		}
		inline int vec4::operator!= ( const vec4 & a ) const { 
			return (( d[0] != a.d[0] ) || ( d[1] != a.d[1] ) || ( d[2] != a.d[2] ) || ( d[3] != a.d[3] ));
		}
		
		//These operators for a single float
		inline vec4 & vec4::operator+= ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] += a;
			return (*this);
		}
		inline vec4 & vec4::operator-= ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] -= a;
			return (*this);
		}
		inline vec4 & vec4::operator*= ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] *= a;
			return (*this);
		}
		inline vec4 & vec4::operator/= ( float a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] /= a;
			return (*this);
		}
		
		//These operators for another vec4
		inline vec4 & vec4::operator+= ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] += a.d[i];
			return (*this);
		}
		inline vec4 & vec4::operator-= ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] -= a.d[i];
			return (*this);
		}
		inline vec4 & vec4::operator*= ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] *= a.d[i];
			return (*this);
		}
		inline vec4 & vec4::operator/= ( const vec4 & a ) {
			for ( unsigned i = 0; i < e; i++ ) this.d[i] /= a.d[i];
			return (*this);
		}
}

inline float sum ( const vec4 & a ) {
	float retVar = 0;
	for ( unsigned i = 0; i < e; i++ ) retVar += d[i];
	return retVar;
}
inline float sqrMag ( const vec4 & a ) {
	float retVar = 0;
	for ( unsigned i = 0; i < e; i++ ) retVar += (d[i]*d[i]);
	return retVar;
}
inline float mag ( const vec4 & a ) {
	return sqrt ( sqrMag ( a ) );
}
inline float normalize ( const vec4 & a ) {
	float retVar = mag ( a );
	a /= retVar;
	return retVar;
}

inline float dot ( const vec4 & a, const vec4 & b ) {
	float retVar = 0;
	for ( unsigned i = 0; i < e; i++ ) retVar += a.d[i]*b.d[i];
	return retVar;
}
inline float cross3 ( const vec4 & a, const vec4 & b ) {
	return vec4 ( a.d[1]*b.d[2] - b.d[1]*a.d[2], a.d[2]*b.d[0] - b.d[2]*a.d[0], a.d[0]*b.d[1] - b.d[0]*a.d[1] );
}
inline float box ( const vec4 & a, const vec4 & b, const vec4 & c ) {
	return dot(cross3(a,b),c);
}
