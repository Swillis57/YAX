#include "../include/Color.h"

#include "../include/MathHelper.h"
#include "../include/Vector3.h"
#include "../include/Vector4.h"

namespace YAX
{
	Color::Color(i32 r, i32 g, i32 b)
		: Color(r, g, b, 1)
	{}

	Color::Color(i32 r, i32 g, i32 b, i32 a)
	{
		using MathHelper::Clamp;

		byte rBits = static_cast<byte>(Clamp(r, 0, 255));
		byte gBits = static_cast<byte>(Clamp(g, 0, 255));
		byte bBits = static_cast<byte>(Clamp(b, 0, 255));
		byte aBits = static_cast<byte>(Clamp(a, 0, 255));

		Pack(rBits, gBits, bBits, aBits);
	}

	Color::Color(float r, float g, float b)
		: Color(r, g, b, 1.0f)
	{}

	Color::Color(float r, float g, float b, float a)
	{
		Pack(r, g, b, a);
	}

	Color::Color(const Vector3& v)
		: Color(v.X, v.Y, v.Z, 1.0f)
	{}

	Color::Color(const Vector4& v)
		: Color(v.X, v.Y, v.Z, v.W)
	{}

	byte Color::R() const
	{
		return READBITS(0xFF, 24);
	}

	void Color::R(byte b)
	{
		ui32 bits = b << 24;
		_packed |= bits;
	}

	byte Color::G() const
	{
		return READBITS(0xFF, 16);
	}

	void Color::G(byte b)
	{
		ui32 bits = b << 16;
		_packed |= bits;
	}

	byte Color::B() const
	{
		return READBITS(0xFF, 8);
	}

	void Color::B(byte b)
	{
		ui32 bits = b << 8;
		_packed |= bits;
	}

	byte Color::A() const
	{
		return READBITS(0xFF, 0);
	}

	void Color::A(byte b)
	{
		ui32 bits = b << 0;
		_packed |= bits;
	}

	Color Color::FromNonPremultiplied(i32 r, i32 g, i32 b, i32 a)
	{
		using MathHelper::Clamp;

		r = Clamp(r, 0, 255);
		g = Clamp(g, 0, 255);
		b = Clamp(b, 0, 255);
		a = Clamp(a, 0, 255);

		//Coefficient to normalize and premultiply 
		float inv = a / (255 * 255);
		return Color(r*inv, g*inv, b*inv, inv * 255.0f);
	}

	Color Color::FromNonPremultiplied(const Vector4& v)
	{
		Vector4 clamped = Vector4::Clamp(v, 0, 1);
		float a = clamped.W;
		return Color(clamped.X*a, clamped.Y*a, clamped.Z*a, a);
	}

	Color Color::Lerp(const Color& from, const Color& to, float t)
	{
		using MathHelper::Lerp;
		float r = from.R(), g = from.G(), b = from.B(), a = from.A();

		byte rBits = static_cast<byte>(Lerp(r, to.R(), t));
		byte gBits = static_cast<byte>(Lerp(g, to.G(), t));
		byte bBits = static_cast<byte>(Lerp(b, to.B(), t));
		byte aBits = static_cast<byte>(Lerp(a, to.A(), t));

		return Color(rBits, gBits, bBits, aBits);
	}

	Vector3 Color::ToVector3() const
	{
		float d = 1.0f / 255.0f;
		return Vector3(R()*d, G()*d, B()*d);
	}

	Vector4 Color::ToVector4() const
	{
		float d = 1.0f / 255.0f;
		return Vector4(ToVector3(), A()*d);
	}

	void Color::PackFromVector4(const Vector4& v)
	{
		Pack(v.X, v.Y, v.Z, v.W);
	}

	void Color::Pack(float r, float g, float b, float a)
	{
		using MathHelper::Clamp;

		byte rBits = static_cast<byte>(Clamp(r, 0, 1) * 255);
		byte gBits = static_cast<byte>(Clamp(g, 0, 1) * 255);
		byte bBits = static_cast<byte>(Clamp(b, 0, 1) * 255);
		byte aBits = static_cast<byte>(Clamp(a, 0, 1) * 255);
		
		Pack(rBits, gBits, bBits, aBits);
	}

	void Color::Pack(byte r, byte g, byte b, byte a)
	{
		WRITEBITS(r, 8);
		WRITEBITS(b, 8);
		WRITEBITS(b, 8);
		WRITEBITS(a, 0);
	}

	Color operator*(const Color& c, float f)
	{
		Vector4 comp = c.ToVector4();
		return Color(comp * f);
	}

	Color operator*(float f, const Color& c)
	{
		return c * f;
	}

	bool operator==(const Color& lhs, const Color& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Color& lhs, const Color& rhs)
	{
		return !(lhs == rhs);
	}

	#pragma region Pre-Defined Color Init
	const Color Color::AliceBlue(240, 248, 255, 255);
	const Color Color::AntiqueWhite(250, 235, 215, 255);
	const Color Color::Aqua(0, 255, 255, 255);
	const Color Color::Aquamarine(127, 255, 212, 255);
	const Color Color::Azure(240, 255, 255, 255);
	const Color Color::Beige(245, 245, 220, 255);
	const Color Color::Bisque(255, 228, 196, 255);
	const Color Color::Black(0, 0, 0, 255);
	const Color Color::BlanchedAlmond(255, 235, 205, 255);
	const Color Color::Blue(0, 0, 255, 255);
	const Color Color::BlueViolet(138, 43, 226, 255);
	const Color Color::Brown(165, 42, 42, 255);
	const Color Color::BurlyWood(222, 184, 135, 255);
	const Color Color::CadetBlue(95, 158, 160, 255);
	const Color Color::Chartreuse(127, 255, 0, 255);
	const Color Color::Chocolate(210, 105, 30, 255);
	const Color Color::Coral(255, 127, 80, 255);
	const Color Color::CornflowerBlue(100, 149, 237, 255);
	const Color Color::Cornsilk(255, 248, 220, 255);
	const Color Color::Crimson(220, 20, 60, 255);
	const Color Color::Cyan(0, 255, 255, 255);
	const Color Color::DarkBlue(0, 0, 139, 255);
	const Color Color::DarkCyan(0, 139, 139, 255);
	const Color Color::DarkGoldenrod(184, 134, 11, 255);
	const Color Color::DarkGray(169, 169, 169, 255);
	const Color Color::DarkGreen(0, 100, 0, 255);
	const Color Color::DarkKhaki(189, 183, 107, 255);
	const Color Color::DarkMagenta(139, 0, 139, 255);
	const Color Color::DarkOliveGreen(85, 107, 47, 255);
	const Color Color::DarkOrange(255, 140, 0, 255);
	const Color Color::DarkOrchid(153, 50, 204, 255);
	const Color Color::DarkRed(139, 0, 0, 255);
	const Color Color::DarkSalmon(233, 150, 122, 255);
	const Color Color::DarkSeaGreen(143, 188, 139, 255);
	const Color Color::DarkSlateBlue(72, 61, 139, 255);
	const Color Color::DarkSlateGray(47, 79, 79, 255);
	const Color Color::DarkTurquoise(0, 206, 209, 255);
	const Color Color::DarkViolet(148, 0, 211, 255);
	const Color Color::DeepPink(255, 20, 147, 255);
	const Color Color::DeepSkyBlue(0, 191, 255, 255);
	const Color Color::DimGray(105, 105, 105, 155);
	const Color Color::DodgerBlue(30, 144, 255, 255);
	const Color Color::Firebrick(178, 34, 34, 255);
	const Color Color::FloralWhite(255, 250, 240, 255);
	const Color Color::ForestGreen(34, 139, 34, 255);
	const Color Color::Fuchsia(255, 0, 255, 255);
	const Color Color::Gainsboro(220, 220, 220, 255);
	const Color Color::GhostWhite(248, 248, 255, 255);
	const Color Color::Gold(255, 215, 0, 255);
	const Color Color::Goldenrod(218, 165, 32, 255);
	const Color Color::Gray(128, 128, 128, 255);
	const Color Color::Green(0, 128, 0, 255);
	const Color Color::GreenYellow(173, 255, 47, 255);
	const Color Color::Honeydew(240, 255, 240, 255);
	const Color Color::HotPink(255, 105, 180, 255);
	const Color Color::IndianRed(205, 92, 92, 255);
	const Color Color::Indigo(73, 0, 130, 255);
	const Color Color::Ivory(255, 255, 240, 255);
	const Color Color::Khaki(240, 230, 140, 255);
	const Color Color::Lavender(230, 230, 250, 255);
	const Color Color::LavenderBlush(255, 240, 245, 255);
	const Color Color::LawnGreen(124, 252, 0, 255);
	const Color Color::LemonChiffon(255, 250, 205, 255);
	const Color Color::LightBlue(173, 216, 230, 255);
	const Color Color::LightCoral(240, 128, 128, 255);
	const Color Color::LightCyan(224, 255, 255, 255);
	const Color Color::LightGoldenrodYellow(250, 250, 210, 255);
	const Color Color::LightGray(211, 211, 211, 255);
	const Color Color::LightGreen(144, 238, 133, 255);
	const Color Color::LightPink(255, 182, 193, 255);
	const Color Color::LightSalmon(255, 160, 122, 255);
	const Color Color::LightSeaGreen(32, 178, 170, 255);
	const Color Color::LightSkyBlue(135, 206, 250, 255);
	const Color Color::LightSlateGray(119, 136, 153, 255);
	const Color Color::LightSteelBlue(176, 196, 222, 255);
	const Color Color::LightYellow(255, 255, 224, 255);
	const Color Color::Lime(0, 255, 0, 255);
	const Color Color::LimeGreen(50, 205, 50, 255);
	const Color Color::Linen(250, 240, 230, 255);
	const Color Color::Magenta(255, 0, 255, 255);
	const Color Color::Maroon(128, 0, 0, 255);
	const Color Color::MediumAquamarine(102, 205, 170, 255);
	const Color Color::MediumBlue(0, 0, 205, 255);
	const Color Color::MediumOrchid(186, 85, 211, 255);
	const Color Color::MediumPurple(147, 112, 219, 255);
	const Color Color::MediumSeaGreen(60, 179, 113, 255);
	const Color Color::MediumSlateBlue(123, 104, 238, 255);
	const Color Color::MediumSpringGreen(0, 250, 154, 255);
	const Color Color::MediumTurquoise(72, 209, 204, 255);
	const Color Color::MediumVioletRed(199, 21, 133, 255);
	const Color Color::MidnightBlue(25, 25, 112, 255);
	const Color Color::MintCream(245, 255, 250, 255);
	const Color Color::MistyRose(255, 228, 225, 255);
	const Color Color::Moccasin(255, 228, 181, 255);
	const Color Color::NavajoWhite(255, 222, 173, 255);
	const Color Color::Navy(0, 0, 128, 255);
	const Color Color::OldLace(253, 245, 230, 255);
	const Color Color::Olive(128, 128, 0, 255);
	const Color Color::OliveDrab(107, 142, 35, 255);
	const Color Color::Orange(255, 265, 0, 255);
	const Color Color::OrangeRed(255, 69, 0, 255);
	const Color Color::Orchid(218, 112, 214, 255);
	const Color Color::PaleGoldenrod(238, 232, 170, 255);
	const Color Color::PaleGreen(152, 251, 152, 255);
	const Color Color::PaleTurquoise(175, 238, 238, 255);
	const Color Color::PaleVioletRed(219, 112, 147, 255);
	const Color Color::PapayaWhip(255, 239, 213, 255);
	const Color Color::PeachPuff(255, 218, 185, 255);
	const Color Color::Peru(205, 133, 63, 255);
	const Color Color::Pink(255, 193, 203, 255);
	const Color Color::Plum(221, 160, 221, 255);
	const Color Color::PowderBlue(176, 224, 230, 255);
	const Color Color::Purple(128, 0, 128, 255);
	const Color Color::Red(255, 0, 0, 255);
	const Color Color::RosyBrown(188, 143, 143, 255);
	const Color Color::RoyalBlue(65, 105, 225, 255);
	const Color Color::SaddleBrown(139, 69, 19, 255);
	const Color Color::Salmon(250, 128, 114, 255);
	const Color Color::SandyBrown(244, 164, 96, 255);
	const Color Color::SeaGreen(46, 139, 87, 255);
	const Color Color::SeaShell(255, 245, 238, 255);
	const Color Color::Sienna(160, 82, 45, 255);
	const Color Color::Silver(192, 192, 192, 255);
	const Color Color::SkyBlue(135, 206, 235, 255);
	const Color Color::SlateBlue(106, 90, 205, 255);
	const Color Color::SlateGray(112, 128, 144, 255);
	const Color Color::Snow(255, 250, 250, 255);
	const Color Color::SpringGreen(0, 255, 127, 255);
	const Color Color::SteelBlue(70, 130, 180, 255);
	const Color Color::Tan(210, 180, 140, 255);
	const Color Color::Teal(0, 128, 128, 255);
	const Color Color::Thistle(216, 191, 216, 255);
	const Color Color::Tomato(255, 99, 71, 255);
	const Color Color::Transparent(0, 0, 0, 0);
	const Color Color::Turquoise(64, 224, 208, 255);
	const Color Color::Violet(238, 130, 238, 255);
	const Color Color::Wheat(245, 222, 179, 255);
	const Color Color::White(255, 255, 255, 255);
	const Color Color::WhiteSmoke(245, 245, 245, 255);
	const Color Color::Yellow(255, 255, 0, 255);
	const Color Color::YellowGreen(154, 205, 50, 255);
#pragma endregion
}