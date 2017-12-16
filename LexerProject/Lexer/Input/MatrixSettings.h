#ifndef PROJECT_MATRIXSETTINGS_H
#define PROJECT_MATRIXSETTINGS_H

#include "ReadVectorMethod.h"
#include "ReadLimit.h"
#include "BaseSettings.h"


class MatrixSettings: public BaseSettings
{
public:
	MatrixSettings() = default;

	MatrixSettings(
			const std::vector<char> & skipSymbols,
			ReadVectorMethod readVectorMethod,
			size_t readLimit
	)
			: BaseSettings(skipSymbols, readVectorMethod, readLimit)
	{}
};

#endif //PROJECT_MATRIXSETTINGS_H
