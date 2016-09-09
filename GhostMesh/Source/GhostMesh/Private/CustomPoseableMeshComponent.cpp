////////////////////////////////////////////////////////////
//
// Copyright (C) 2016 Noah Zuo (noahzuo1994@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////
#include "GhostMeshPrivatePCH.h"
#include "CustomPoseableMeshComponent.h"
#include "NoahZuoLib.h"



void UCustomPoseableMeshComponent::MakePoseBySkeletalMesh(USkeletalMeshComponent* SkeletalMeshComp)
{
	auto skelton = SkeletalMeshComp->SkeletalMesh;
	if (!IsValid(skelton))
	{
		return ;
	}
	
	TArray<FName> nameArr = UNoahZuoLib::GetSkeletalBoneNames(skelton);

	for(int i = 0; i < nameArr.Num(); i++)
	{
		auto socketTransform = SkeletalMeshComp->GetSocketTransform(nameArr[i],RTS_Component);
		SetBoneTransformByName(nameArr[i], socketTransform, EBoneSpaces::ComponentSpace);
	}
}