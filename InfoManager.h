/***************************************************************
 *
 *      @Author:                Walter White
 *      @Create Date:           2021/6/21
 *      @Last Modified Date:    2021/6/21
 *
 *      @Descript:
 *          信息的管理类，存放各种信息
 *
 *          @Param:
 *              imageFileName:      图像的位置信息
 *
 *
 ***************************************************************
 * */
#ifndef TRIANGLEDOMAIN_INFOMANAGER_H
#define TRIANGLEDOMAIN_INFOMANAGER_H

#include "include/SamplingData.h"

namespace TriangleDomain {

    class InfoManager {
    public:
        std::string imageFileName = "D:\\Project\\QtProject\\triangleDomain\\Images\\Lena.png";

        std::vector<std::vector<SamplingData>> data;
        std::vector<std::vector<SamplingData>> sectionData;
        std::vector<std::vector<SamplingData>> maskData;

        int domainType = 1;

        int functionType = 1;

        int permitError;

        bool showMask = true;
    };
}


#endif //TRIANGLEDOMAIN_INFOMANAGER_H
