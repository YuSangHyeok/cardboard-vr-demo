//
//  VRDistortionMeshHelper.hpp
//  SDKSamplesApp
//
//  Created by Ali on 3/31/16.
//
//

#ifndef VRDistortionMeshHelper_h
#define VRDistortionMeshHelper_h

#include "Types.h"
#include "VectorMath.h"
#include <vector>
#include "VRCardboardDeviceProfile.h"

namespace Eegeo
{
    namespace VR
    {
        namespace Distortion
        {
            struct Vertex
            {
                Eegeo::v3 position;
                Eegeo::v3 normal;
                Eegeo::v2 uv;
                
                Vertex()
                : position(Eegeo::v3::Zero())
                , normal(Eegeo::v3::Zero())
                , uv(Eegeo::v2::Zero())
                {
                }
                
                Vertex(const Eegeo::v3& position, const Eegeo::v3& normal, const Eegeo::v2 uv)
                : position(position)
                , normal(normal)
                , uv(uv)
                {
                }
            };
            
            void BuildBox(const Eegeo::v3& halfDimensions, std::vector<Vertex>& out_vertices, std::vector<u16>& out_triangleIndices);
            void BuildDistortionMesh(std::vector<Vertex>& out_vertices, std::vector<u16>& out_triangleIndices, int screenWidth, int screenHeight, VRCardboardDeviceProfile profile);
        }
    }
}


#endif /* VRDistortionMeshHelper_hpp */
