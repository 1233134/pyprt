/**
 * PyPRT - Python Bindings for the Procedural Runtime (PRT) of CityEngine
 *
 * Copyright (c) 2012-2020 Esri R&D Center Zurich
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * A copy of the license is available in the repository's LICENSE file.
 */

#pragma once

#include "GeneratedPayload.h"
#include "types.h"

#include <pybind11/pybind11.h>

#include <cstddef>
#include <cstdint>
#include <vector>

class GeneratedModel {
public:
	GeneratedModel(const size_t& initialShapeIdx, const Coordinates& vert, const Indices& indices, const Indices& face,
	               const pybind11::dict& rep, const std::wstring& cgaPrints, const std::vector<std::wstring>& cgaErrors,
				   const pybind11::dict& attrVal);
	GeneratedModel() = default;
	~GeneratedModel() = default;

	size_t getInitialShapeIndex() const {
		return mInitialShapeIndex;
	}
	const Coordinates& getVertices() const {
		return mPayload.mVertices;
	}
	const Indices& getIndices() const {
		return mPayload.mIndices;
	}
	const Indices& getFaces() const {
		return mPayload.mFaces;
	}
	const pybind11::dict& getReport() const {
		return mPayload.mCGAReport;
	}
	const std::wstring& getCGAPrints() const {
		return mPayload.mCGAPrints;
	}
	const std::vector<std::wstring>& getCGAErrors() const {
		return mPayload.mCGAErrors;
	}
	const pybind11::dict& getAttributes() const {
		return mPayload.mAttrVal;
	}

private:
	size_t mInitialShapeIndex;
	GeneratedPayload mPayload;
};

PYBIND11_MAKE_OPAQUE(std::vector<GeneratedModel>);
