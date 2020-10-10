#pragma once

namespace helper
{


	struct Vector2f
	{
		float X;
		float Y;

		Vector2f()
		{
			X = 0.0f;
			Y = 0.0f;
		}

		Vector2f(float X, float Y)
		{
			this->X = X;
			this->Y = Y;
		}

	};

	struct Vector2i
	{
		int X;
		int Y;

		Vector2i()
		{
			X = 0;
			Y = 0;
		}

		Vector2i(int X, int Y)
		{
			this->X = X;
			this->Y = Y;
		}
	};

	struct Vector2d
	{
		double X;
		double Y;

		Vector2d()
		{
			X = 0.0;
			Y = 0.0;
		}

		Vector2d(int X, int Y)
		{
			this->X = X;
			this->Y = Y;
		}
	};

	struct Vector2l
	{
		long X;
		long Y;

		Vector2l()
		{
			X = 0;
			Y = 0;
		}

		Vector2l(int X, int Y)
		{
			this->X = X;
			this->Y = Y;
		}

	};

	struct Vector3f
	{
		float X;
		float Y;
		float Z;

		Vector3f()
		{
			X = 0.0f;
			Y = 0.0f;
			Z = 0.0f;
		}

		Vector3f(float X, float Y, float Z)
		{
			this->X = X;
			this->Y = Y;
			this->Z = Z;
		}

	};

	struct Vector3i
	{
		int X;
		int Y;
		int Z;

		Vector3i()
		{
			X = 0;
			Y = 0;
			Z = 0;
		}

		Vector3i(int X, int Y, int Z)
		{
			this->X = X;
			this->Y = Y;
			this->Z = Z;
		}
	};

	struct Vector3d
	{
		double X;
		double Y;
		double Z;

		Vector3d()
		{
			X = 0.0;
			Y = 0.0;
			Z = 0.0;
		}

		Vector3d(double X, double Y, double Z)
		{
			this->X = X;
			this->Y = Y;
			this->Z = Z;
		}
	};

	struct Vector3l
	{
		long X;
		long Y;
		long Z;

		Vector3l()
		{
			X = 0;
			Y = 0;
			Z = 0;
		}

		Vector3l(long X, long Y, long Z)
		{
			this->X = X;
			this->Y = Y;
			this->Z = Z;
		}

	};

	//=====================================================//

	struct Recti
	{
		int X;
		int Y;
		int Width;
		int Height;

		Recti()
		{
			X = 0;
			Y = 0;
			Width = 0;
			Height = 0;
		}

		Recti(int X, int Y, int Width, int Height)
		{
			this->X = X;
			this->Y = Y;
			this->Width = Width;
			this->Height = Height;
		}

		Recti(int Width, int Height)
		{
			this->X = 0;
			this->Y = 0;
			this->Width = Width;
			this->Height = Height;
		}
	};

	struct Rectf
	{
		float X;
		float Y;
		float Width;
		float Height;

		Rectf()
		{
			X = 0;
			Y = 0;
			Width = 0;
			Height = 0;
		}

		Rectf(float X, float Y, float Width, float Height)
		{
			this->X = X;
			this->Y = Y;
			this->Width = Width;
			this->Height = Height;
		}

		Rectf(float Width, float Height)
		{
			this->X = 0;
			this->Y = 0;
			this->Width = Width;
			this->Height = Height;
		}
	};

	struct Rectd
	{
		double X;
		double Y;
		double Width;
		double Height;

		Rectd()
		{
			X = 0;
			Y = 0;
			Width = 0;
			Height = 0;
		}

		Rectd(double X, double Y, double Width, double Height)
		{
			this->X = X;
			this->Y = Y;
			this->Width = Width;
			this->Height = Height;
		}

		Rectd(double Width, double Height)
		{
			this->X = 0;
			this->Y = 0;
			this->Width = Width;
			this->Height = Height;
		}
	};

	struct Rectl
	{
		long X;
		long Y;
		long Width;
		long Height;

		Rectl()
		{
			X = 0;
			Y = 0;
			Width = 0;
			Height = 0;
		}

		Rectl(long X, long Y, long Width, long Height)
		{
			this->X = X;
			this->Y = Y;
			this->Width = Width;
			this->Height = Height;
		}

		Rectl(long Width, long Height)
		{
			this->X = 0;
			this->Y = 0;
			this->Width = Width;
			this->Height = Height;
		}
	};
}