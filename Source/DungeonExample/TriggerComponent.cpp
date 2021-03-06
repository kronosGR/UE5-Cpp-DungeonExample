// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Called when the game starts
UTriggerComponent::UTriggerComponent() {

	// enables ticking
	PrimaryComponentTick.bCanEverTick = true;
}


void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void  UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Actor = GetAcceptableActor();
	if (Actor != nullptr) {
	    UPrimitiveComponent* Component = 	Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr) {
			Component->SetSimulatePhysics(false);
		}
		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		Mover->SetShouldMove(true);
		UE_LOG(LogTemp, Display, TEXT("Unlock"));
	}
	else {
		Mover->SetShouldMove(false);
		UE_LOG(LogTemp, Display, TEXT("Unlock"));
	}
}

AActor* UTriggerComponent::GetAcceptableActor() const {
	
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	/*for (int num = 0; num < Actors.Num(); num++) {
		FString ActorName = Actors[num]->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
	}*/

	// Alternative loop
	for (AActor* Actor : Actors) {
		bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");
		if (HasAcceptableTag && !IsGrabbed ) {
			return Actor;
		}
	}

	return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover) {
	Mover = NewMover;
}