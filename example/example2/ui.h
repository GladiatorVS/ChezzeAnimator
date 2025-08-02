#include "imgui.h"
#include "../Animator.h"

void Example1();
void Example2();
void Example3();

void Draw()
{

	if (ImGui::BeginTabBar("Examples"))
	{
		if (ImGui::BeginTabItem("Example 1"))
		{
			Example1();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Example 2"))
		{
			Example2();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Example 3"))
		{
			Example3();
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
}

void Example1()
{
	ImGui::Text("===== Example 1 =====");

	static float b = 50;

	static ChezzeAnimator buttonAnim(&b, 200, ChezzeAnimator::InOutQuad, 1000);

	ImGui::BeginDisabled(buttonAnim.isStarted());

	if (ImGui::Button("Start"))
	{
		buttonAnim.setToValue(b == 200 ? 50 : 200);

		buttonAnim.start();
	}

	ImGui::EndDisabled();

	buttonAnim.update();

	ImGui::BeginDisabled();

	ImGui::Button("Abc##ex1.b1", {b, b});

	ImGui::EndDisabled();
}

void Example2()
{
	ImGui::Text("===== Example 2 =====");

	static float b1 = 50;
	static float b2 = 100;

	static ChezzeAnimator firstButtonAnim(&b1, 0, ChezzeAnimator::OutCubic, 1500);
	static ChezzeAnimator secondButtonAnim(&b2, 0, ChezzeAnimator::OutCubic, 1500);

	ImGui::BeginDisabled(firstButtonAnim.isStarted() || secondButtonAnim.isStarted());

	if (ImGui::Button("Start"))
	{
		firstButtonAnim.setToValue(b1 == 50 ? 100 : 50);
		secondButtonAnim.setToValue(b2 == 50 ? 100 : 50);

		firstButtonAnim.start();
		secondButtonAnim.start();
	}

	ImGui::EndDisabled();

	firstButtonAnim.update();
	secondButtonAnim.update();

	ImGui::BeginDisabled();

	ImGui::Button("Abc##ex1.b1", { b1, 150 });
	ImGui::SameLine();
	ImGui::Button("123##ex1.b2", { b2, 150 });

	ImGui::EndDisabled();
}

void Example3()
{
	ImGui::Text("===== Example 3 =====");

	static bool ex3started = false;
	static bool ex3init = false;

	static float obj1size = 10;
	static float obj2size = 150;

	static auto OutAnim = ChezzeAnimator::OutCubic;
	static auto InAnim = ChezzeAnimator::InCubic;

	static ChezzeAnimator ex3firstAnim(&obj1size, 150, OutAnim, 3000);
	static ChezzeAnimator ex3secondAnim(&obj2size, 10, InAnim, 3000);

	if (!ex3init)
	{
		ex3firstAnim.setCompleteCallback([]()
			{

				if (obj2size == 10)
				{
					ex3secondAnim.setToValue(150);
					ex3secondAnim.setType(OutAnim);
				}
				else
				{
					ex3secondAnim.setToValue(10);
					ex3secondAnim.setType(InAnim);
				}

				ex3secondAnim.start();
			});
		ex3secondAnim.setCompleteCallback([]()
			{
				if (obj1size == 10)
				{
					ex3firstAnim.setToValue(150);
					ex3firstAnim.setType(OutAnim);
				}
				else
				{
					ex3firstAnim.setToValue(10);
					ex3firstAnim.setType(InAnim);
				}
				ex3firstAnim.start();
			});

		ex3init = true;
	}

	if (ImGui::Button(ex3started ? "Stop" : "Start"))
	{
		if (ex3started)
		{
			ex3firstAnim.stop();
			ex3secondAnim.stop();

			obj1size = 10;
			obj2size = 150;

			ex3firstAnim.setStartValue(obj1size);
			ex3secondAnim.setStartValue(obj2size);

			ex3started = false;
		}
		else
		{
			ex3firstAnim.start();
			ex3started = true;
		}

	}

	ex3firstAnim.update();
	ex3secondAnim.update();

	ImGui::Button("##ex3.b1", {100,obj1size});
	ImGui::SameLine();
	ImGui::Button("##ex3.b2", {100,obj2size});

}