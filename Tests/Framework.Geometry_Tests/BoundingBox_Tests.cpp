
#if 0
#include "../catch.h"
#include "../../Framework.Geometry/include/BoundingBox.h"
#include "../../Framework.Math/include/Vector3.h"
#include "../../Framework.Geometry/include/Ray.h"
#include "../../Framework.Geometry/include/ContainmentType.h"

using namespace YAX;

TEST_CASE("BoundingBox has correct functionality", "[BoundingBox]")
{
	SECTION("Contains correctly computes BoundingBox containment types")
	{
		BoundingBox bbLarge(Vector3(-2, -2, -2), Vector3(2, 2, 2));
		BoundingBox bbSmall(Vector3(-1, -1, -1), Vector3(1, 1, 1));
		BoundingBox bbRect(Vector3(0, 0, 0), Vector3(1, 2, 3));
		BoundingBox bbDisjoint(Vector3(-5, -5, -5), Vector3(-3, -3, -3));

		REQUIRE(bbLarge.Contains(bbSmall) == ContainmentType::Contains);
		REQUIRE(bbLarge.Contains(bbDisjoint) == ContainmentType::Disjoint);
		REQUIRE(bbSmall.Contains(bbLarge) == ContainmentType::Intersects);
		REQUIRE(bbLarge.Contains(bbRect) == ContainmentType::Intersects);
	}

	
}
#endif