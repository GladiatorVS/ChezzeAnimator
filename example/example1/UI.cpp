#include "UI.h"
#include "imgui.h"

#include "../Animator.h"

ChZUI::ChZUI()
{
	
}

void ChZUI::Draw()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	if (!ImGui::Begin("app", nullptr, 
		/*ImGuiWindowFlags_MenuBar |*/ ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings)) 
		return;
	
	DrawContent();

	ImGui::End();
}

#define GEN_STRING(name) #name,

static const char* const AnimTypeNames[] = {
	EASING_LIST(GEN_STRING)
};

inline void ChZUI::DrawContent()
{
	static int currentAnimIndex = ChezzeAnimator::InOutExpo;
	static auto anim = static_cast<ChezzeAnimator::AnimType>(currentAnimIndex);

	if (ImGui::BeginCombo("Easing Type", AnimTypeNames[currentAnimIndex])) {
		for (int i = 0; i < ChezzeAnimator::AnimTypeCount; ++i) {
			bool isSelected = (currentAnimIndex == i);
			if (ImGui::Selectable(AnimTypeNames[i], isSelected)) {
				currentAnimIndex = i;
				anim = static_cast<ChezzeAnimator::AnimType>(i);
			}
			if (isSelected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}

	ImGui::Dummy({ 0,10 });
	ImGui::Separator();
	ImGui::Dummy({ 0,10 });

	{
		static float x = 100;
		static float y = 100;

		static float speedMs = 1000;
		static ChezzeAnimator anim1X(&x, 0, anim, speedMs);
		static ChezzeAnimator anim1Y(&y, 0, anim, speedMs);

		if (ImGui::DragFloat("Speed (Ms)", &speedMs, 1.f, 1, 5000))
		{
			anim1X.setSpeed(speedMs);
			anim1Y.setSpeed(speedMs);
		}

		anim1X.setType(anim);
		anim1Y.setType(anim);

		ImGui::BeginDisabled(anim1X.isStarted() || anim1Y.isStarted());

		if (ImGui::Button("start"))
		{
			anim1X.setToValue(x != 100.f ? 100.f : 200.f);
			anim1Y.setToValue(y != 100.f ? 100.f : 200.f);

			anim1X.start();
			anim1Y.start();
		}

		ImGui::EndDisabled();

		anim1X.update();
		anim1Y.update();

		ImGui::SameLine();

		ImGui::BeginDisabled();
		ImGui::Button("##No#Text#Button#", { x, y });
		ImGui::EndDisabled();
	}

	ImGui::Dummy({ 0,10 });
	ImGui::Separator();
	ImGui::Dummy({ 0,10 });

	{
		static float animColorR = 0;
		static float animColorG = 1.0f;

		static float color_speedMs = 1000;
		static ChezzeAnimator color_anim1(&animColorR, 0, anim, color_speedMs);
		static ChezzeAnimator color_anim2(&animColorG, 0, anim, color_speedMs);

		if (ImGui::DragFloat("Speed (Ms)##colorspeed", &color_speedMs, 1.f, 1, 5000))
		{
			color_anim1.setSpeed(color_speedMs);
			color_anim2.setSpeed(color_speedMs);
		}

		color_anim1.setType(anim);
		color_anim2.setType(anim);

		ImGui::BeginDisabled(color_anim1.isStarted() || color_anim2.isStarted());

		if (ImGui::Button("start##coloranim"))
		{
			color_anim1.setToValue(animColorR != 0.f ? 0.f : 1.f);
			color_anim2.setToValue(animColorG != 0.f ? 0.f : 1.f);

			color_anim1.start();
			color_anim2.start();
		}

		ImGui::EndDisabled();

		color_anim1.update();
		color_anim2.update();

		ImGui::TextColored({ animColorR,animColorG,1.f,1.f }, "HELLO! WORLD!");
	}

	ImGui::Dummy({ 0,10 });
	ImGui::Separator();
	ImGui::Dummy({ 0,10 });

	{
		static float opacity = 1.f;

		static float opacity_speedMs = 1000;
		static ChezzeAnimator op_anim1(&opacity, 0, ChezzeAnimator::InOutExpo, opacity_speedMs);

		if (ImGui::DragFloat("Speed (Ms)##opacspeed", &opacity_speedMs, 1.f, 1, 5000))
		{
			op_anim1.setSpeed(opacity_speedMs);
		}

		op_anim1.setType(anim);

		ImGui::BeginDisabled(op_anim1.isStarted());

		if (ImGui::Button("start##opanim"))
		{
			op_anim1.setToValue(opacity != 0.f ? 0.f : 1.f);
			op_anim1.start();
		}

		ImGui::EndDisabled();

		op_anim1.update();


		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.f, 1.f, 1.f, opacity));

		ImGui::BeginDisabled();
		ImGui::Button("##OpButton", ImVec2(100, 100));
		ImGui::EndDisabled();

		ImGui::PopStyleColor(1);
	}
}

