#pragma once
#include "vector.h"
#include "memory.h"
#include <string>
#include "memmane.h"
bool IsValidPtr(void* pointer);
 bool IsValidPtr2(void* pointer)
{
	if (!pointer)
		return false;

	if (pointer < (void*)0xFFF)
		return false;

	if (pointer > (void*)0x7FFFFFFFFFFF)
		return false;

	return true;
}
namespace Game
{
	uint64_t GetInventory(uint64_t Entity)
	{
		if (!IsValidPtr2((void*)Entity))
			return 0;

		return mem1->RVM<uint64_t>(Entity + 0x658);
	}

	std::string FetchHands(uint64_t Entity)
	{
		auto Getch1 = Game::GetInventory(Entity);
		if (!Getch1)
			return "";

		return ReadArmaString(mem1->RVM<uint64_t>(mem1->RVM<uint64_t>(mem1->RVM<uint64_t>(Game::GetInventory(Entity) + 0x1B0) + 0x180) + 0x4E8)).c_str();
	}
	uint64_t NearEntityTable()
	{
		return mem1->RVM<uint64_t>(globals.World + 0xEB8);
	}
	
	uint32_t NearEntityTableSize()
	{
		return mem1->RVM<uint32_t>(globals.World + 0xEB8 + 0x08);
	}

	uint64_t GetEntity(uint64_t PlayerList, uint64_t SelectedPlayer)
	{
		// Sorted Object
		return mem1->RVM<uint64_t>(PlayerList + SelectedPlayer * 0x8);
	}
	struct matrix4x4
	{
		float m[12];
	};
	uint64_t GeVisualState(uint64_t Enity)
	{
		if (!IsValidPtr2((void*)Enity))
			return 0;

		return mem1->RVM<uint64_t>(Enity + 0x1D0);
	}
	BOOL GetBonePosition(DWORD64 skeleton, DWORD64 visual, DWORD index, Vector3* out)
	{
		uint64_t animClass = mem1->RVM<uint64_t>(skeleton + 0x98);
		if (!IsValidPtr2((void*)animClass))
			return 0;


		uint64_t matrixClass = mem1->RVM<uint64_t>(animClass + 0xBF0);
		if (!IsValidPtr2((void*)matrixClass))
			return 0;

		matrix4x4 matrix_a = mem1->RVM< matrix4x4>(visual + 0x8);


		Vector3 matrix_b = mem1->RVM<Vector3>(matrixClass + 0x54 + index * sizeof(matrix4x4));

		out->x = (matrix_a.m[0] * matrix_b.x) + (matrix_a.m[3] * matrix_b.y) + (matrix_a.m[6] * matrix_b.z) + matrix_a.m[9];
		out->y = (matrix_a.m[1] * matrix_b.x) + (matrix_a.m[4] * matrix_b.y) + (matrix_a.m[7] * matrix_b.z) + matrix_a.m[10];
		out->z = (matrix_a.m[2] * matrix_b.x) + (matrix_a.m[5] * matrix_b.y) + (matrix_a.m[8] * matrix_b.z) + matrix_a.m[11];
		return TRUE;
	}
	uint64_t GetSkeleton(uint64_t Entity, int s2) {

		uint64_t Skeleton;

		if (s2 == 1)
			Skeleton = mem1->RVM<uint64_t>(Entity + OFF_skeletonPlayer);

		if (s2 == 2)
			Skeleton = mem1->RVM<uint64_t>(Entity + OFF_skeletonZombie);

		return Skeleton;
	}
	std::string GetEntityTypeName(uint64_t Entity)
	{
		// Render Entity Type + Config Name
		return ReadArmaString(mem1->RVM<uint64_t>(mem1->RVM<uint64_t>(Entity + 0x180) + 0x4E8)).c_str();
	}

 
 

	uint64_t GetLocalPlayer()
	{
		const auto pUWorld = *reinterpret_cast<uint64_t**>(globals.Base + OFF_WORLD);
		if (!IsValidPtr((void*)pUWorld))
			return 0;
		// Sorted Entity Object
		return mem1->RVM<uint64_t>(mem1->RVM<uint64_t>((uint64_t)pUWorld + 0x2960) + 0x8) - 0xA8;
	}

	uint64_t GetLocalPlayerVisualState()
	{
		// Future Visual State
		return mem1->RVM<uint64_t>(GetLocalPlayer() + 0x1D0);
	}

	Vector3 GetCoordinate(uint64_t Entity)
	{
		while (true)
		{
			if (Entity == GetLocalPlayer())
			{
				return Vector3(mem1->RVM<Vector3>(GetLocalPlayerVisualState() + 0x2C));
			}
			else
			{
				return  Vector3(mem1->RVM<Vector3>(mem1->RVM<uint64_t>(Entity + 0x1D0) + 0x2C));
			}
		}
	}
	std::string GetEntityTypeName2(uint64_t Entity)
	{   /// avisa quando for pra testar
		// Render Entity Type + Config Name
		return ReadArmaString(mem1->RVM<uint64_t>(mem1->RVM<uint64_t>(Entity + 0x180) + 0Xa8)).c_str();
	}

	uint64_t GetCamera()
	{
		while (true)
		{
			return mem1->RVM<uint64_t>(globals.World + 0x1B8);
		}
	}

	Vector3 GetInvertedViewTranslation()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0x2C));
	}
	Vector3 GetInvertedViewRight()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0x8));
	}
	Vector3 GetInvertedViewUp()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0x14));
	}
	Vector3 GetInvertedViewForward()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0x20));
	}

	Vector3 GetViewportSize()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0x58));
	}

	Vector3 GetProjectionD1()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0xD0));
	}

	Vector3 GetProjectionD2()
	{
		return Vector3(mem1->RVM<Vector3>(GetCamera() + 0xDC));
	}


	uint32_t GetSlowEntityTableSize()
	{
		return mem1->RVM<uint32_t>(globals.World + OFF_SLOW_ENTITY_TABLE + 0x08);
	}

	float GetDistanceToMe(Vector3 Entity)
	{
		return Entity.Distance(GetCoordinate(GetLocalPlayer()));
	}

	bool WorldToScreen(Vector3 Position, Vector3& output)
	{
		if (!GetCamera()) return false;

		Vector3 temp = Position - GetInvertedViewTranslation();

		float x = temp.Dot(GetInvertedViewRight());
		float y = temp.Dot(GetInvertedViewUp());
		float z = temp.Dot(GetInvertedViewForward());

		if (z < 0.1f)
			return false;

		Vector3 res(
			GetViewportSize().x * (1 + (x / GetProjectionD1().x / z)),
			GetViewportSize().y * (1 - (y / GetProjectionD2().y / z)),
			z);

		output.x = res.x;
		output.y = res.y;
		output.z = res.z;
		return true;
	}
	Vector3 GetObjectVisualState(uintptr_t entity)
	{
		if (entity)
		{
			uintptr_t renderVisualState = mem1->RVM<uintptr_t>(entity + 0x1D0);

			if (!IsValidPtr((void*)renderVisualState))
				return Vector3(-1, -1, -1);

			if (renderVisualState)
			{
				Vector3 pos = mem1->RVM<Vector3>(renderVisualState + 0x2C);
				return pos;
			}
		}

		return Vector3(-1, -1, -1);
	}
	bool SetPosition(uint64_t Entity, Vector3 TargetPosition)
	{
		if (Entity == Game::GetLocalPlayer()) {

			*reinterpret_cast<Vector3*>(mem1->RVM<uint64_t>(Entity + 0xF0) + 0x2C) = TargetPosition;
		}
		else {
			*reinterpret_cast<Vector3*>(mem1->RVM<uint64_t>(Entity + 0x1D0) + 0x2C) = TargetPosition;
		}
		return true;
	}

}