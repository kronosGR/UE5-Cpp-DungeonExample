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
}