//
//  UIInteractionModule.h
//  SDKSamplesApp
//
//  Created by Ali on 5/16/16.
//
//

#pragma once

#include <vector>
#include "ExampleController.h"
#include "IUICameraProvider.h"
#include "IUIInteractableItem.h"
#include "IUIInteractionObservable.h"
#include "../GazeUI/GazeUIView.h"

namespace Eegeo
{
    namespace UI
    {
        class UIInteractionModule : public IUIInteractionObservable
        {
        private:
            struct Ray
            {
                Eegeo::dv3 origin;
                Eegeo::v3 direction;
            };
            
            float m_GazedTime = 0.0f;
            
            GazeUI::GazeUIView& m_GazeUIView;
            int m_FocusedUIItemId;
            
            std::vector<IUIInteractableItem*> m_InteractableItems;
            IUICameraProvider& m_pCameraProvider;
            
            Eegeo::DebugRendering::DebugRenderer& m_debugRenderer;
            
            bool IsScreenPointInsideModel(const Eegeo::v2& screenPoint, IUIInteractableItem* uiItem);
            void CreateWorldSpaceRayFromScreen(const Eegeo::v2& screenPoint, Ray& ray);
        public:
            UIInteractionModule(Eegeo::EegeoWorld& world, IUICameraProvider& p_CameraProvider, GazeUI::GazeUIView& gazeUIView);
            virtual ~UIInteractionModule();
            void Update(float dt);
            void Event_ScreenInteractionStart(const Eegeo::v2& point);
            void Event_ScreenInteractionMoved(const Eegeo::v2& point);
            void Event_ScreenInteractionEnd(const Eegeo::v2& point);
            void Event_ScreenInteractionClick(const Eegeo::v2& point);
            const IUIInteractableItem* GetItemAtScreenPoint(const Eegeo::v2& point);
            virtual void RegisterInteractableItem(IUIInteractableItem* interactableItem);
            virtual void UnRegisterInteractableItem(IUIInteractableItem* interactableItem);
        };
        
    }
}
