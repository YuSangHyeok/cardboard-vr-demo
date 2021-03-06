// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "JumpPointViewFactory.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace UI
    {
        namespace JumpPoints
        {
            
            JumpPointViewFactory::JumpPointViewFactory(IUIRenderableFilter& uiRenderableFilter
                                                       , IUIQuadFactory& uiQuadFactory
                                                       , const UIProgressBarConfig& progressBarConfig
                                                       , Eegeo::Helpers::ICallback1<JumpPoint&>& onJumpPointSelected)
            : m_uiRenderableFilter(uiRenderableFilter)
            , m_uiQuadFactory(uiQuadFactory)
            , m_progressBarConfig(progressBarConfig)
            , m_onJumpPointSelected(onJumpPointSelected)
            {
                
            }
            
            JumpPointViewFactory::~JumpPointViewFactory()
            {
                
            }
            
            JumpPointView* JumpPointViewFactory::CreateViewForJumpPoint(JumpPoint& jumpPointModel)
            {
                JumpPointView* pJumpPointView = Eegeo_NEW(JumpPointView)(jumpPointModel
                                                                        , m_uiRenderableFilter
                                                                        , m_uiQuadFactory
                                                                        , m_progressBarConfig
                                                                        , m_onJumpPointSelected
                                                                        );
                pJumpPointView->SetFadeTransitionSpeed(2.f);
                pJumpPointView->SetColor(Eegeo::v4(1.f,1.f,1.f,0.f));
                return pJumpPointView;
            }
            
        }
    }
}
