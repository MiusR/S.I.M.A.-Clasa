#include "focus_system.h"


void FocusSystem::doLogic(std::vector<Actor*> actors, int current) {

	CameraComponent* camera = actors[current]->GetComponent<CameraComponent>();
	
	DataTransferComponent* transfer = actors[current]->GetComponent<DataTransferComponent>();

	if (transfer->actor != NULL) {
		PositionComponent* target_pos = transfer->actor->GetComponent<PositionComponent>();
		LabelComponent* info = transfer->actor->GetComponent<LabelComponent>();
		PhysicsComponent* physics = transfer->actor->GetComponent<PhysicsComponent>();
		
		if (target_pos != NULL && info != NULL && physics != NULL) {
			Vector3 camera_pos = camera->camera.position;
			Vector3 target = target_pos->transform.translation;

			Vector3 offset = { -25, 0, 0 };

			/// Better to have preset points!!!! 
			offset.y += physics->radius * 4;
			offset.x += physics->radius/4;

			target = Vector3Add(target, offset);
			
			Vector3 new_pos = camera_pos, new_target = camera->camera.target;

			if (!Vector3Equals(camera_pos, target) && Vector3Distance(camera_pos, target) > 0.05) {
				new_pos = Vector3Lerp(camera_pos, target, 0.1);
				new_target = Vector3Lerp(camera->camera.target, target, 0.1);
				
				camera->camera.position = new_pos;
				camera->camera.target = new_target;
			}
			else if(!isShowingInfo){
				isShowingInfo = true;
				info_actor = CreateLabel(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), info->font_size, info->label_text, info->text_color);
			}

		}
	}
	else if (!Vector3Equals(camera->camera.position, camera->initial_position)) {
		
		Vector3 camera_pos = camera->camera.position;
		
		Vector3 new_pos = Vector3Lerp(camera_pos, camera->initial_position, 0.1);
		Vector3 new_target = Vector3Lerp(camera->camera.target, camera->initial_target, 0.1);

		camera->camera.position = new_pos;
		camera->camera.target = new_target;

		if (isShowingInfo) {
			isShowingInfo = false;
			SystemManager::getInstance()->RemoveActor(info_actor);
		}
	}
}

