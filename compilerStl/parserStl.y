%code requires{
#include <Lewis/Session.h>
}

%{
#include <stdio.h>
#include <string.h>
#include <list>
#include <Lewis/Data.h>
#include <Lewis/MeshNew.h>
#include <Lewis/Session.h>
#include <Lewis/Reader.h>
#include <Lewis/TransformationNew.h>
#include <Lewis/PolylineNew.h>
#include <Lewis/CircleNew.h>
#include <Lewis/FunnelNew.h>
#include <Lewis/TunnelNew.h>
#include <Lewis/InstanceNew.h>

extern int stllineno;
extern char* stltext;

extern int stlcolumn;

int stllex(void);
int stlerror(Session* currSession, const char *s) {
  printf("%s on line %d - %s\n", s, stllineno, stltext);
}

int stlwrap() {
    return 1;
}

map<string,QColor> surfaces;
map<string,Vert*> vertices;
std::vector<string> tempVariables;
std::vector<string> tempFaceDelete;
string currentSetName;
std::list<SetNew *> currentSetList;
map<string,std::vector<double>> currentBank;
std::vector<string> currentInstanceList;
std::list<InstanceNew *> currentGroup;
std::list<FaceNew *> currentMeshFaces;
std::list<Vert *> currentMeshVertices;
std::list<EdgeNew *> currentMeshEdges;

std::list<Vert *> currentFaceVertices;
std::list<FaceNew *> currentSolidFace;

std::list<TransformationNew *> currentTransformations;

double *getBankValue2(std::string str, Session* currSession){
    unsigned first = str.find("$") + 1;
    unsigned last = str.find(".");
    string strNew = str.substr (first,last-first);

    for(auto b : currSession->banks) {
        if (b->name == strNew){
            for(auto s : b->sets) {
                if (s->name == str.substr(last + 1)){
                    return &s->value;
                }
            }
        }
    }
    return NULL;
}



%}

%parse-param { Session* currSession }

%token OUTER SOLID FACET ENDFACET LOOP ENDLOOP VERTEX NORMAL ENDSOLID COLOR VARIABLE COMMENT NEWLINE SURFACE END_SURFACE MESH END_MESH FACE END_FACE BEG_POINT
END_POINT OBJECT END_OBJECT BANK END_BANK TUNNEL END_TUNNEL FUNNEL END_FUNNEL
POLYLINE END_POLYLINE INSTANCE END_INSTANCE CIRCLE END_CIRCLE BEG_DELETE END_DELETE
GROUP  END_GROUP TRANSLATE ROTATE MIRROR SET OPARENTHESES EPARENTHESES OBRACE
EXPR DOLLAR EBRACE PERIOD TOKHEAT STATE TOKTARGET TOKTEMPERATURE
SCALE SUBDIVISION END_SUBDIVISION SUBDIVISIONS TYPE OFFSET END_OFFSET MIN MAX STEP
;

%error-verbose
%locations


%union
{
    double number;
    char *string;
    struct {
        char *string; // char *strVal;
        double number;   // int posVal;
    } numPos;
}

%token <string> BANK_EXPR
%token <string> NUMBER

%type <number> num
%type <string> expr

%%

commands: /* empty */
    | commands command
    ;


command:
    solid

    ;

solid:
    SOLID VARIABLE facetsArgs ENDSOLID VARIABLE
    {
        Reader* currReader = createReader(currSession);
        MeshNew* currMesh = createMesh();

        for (std::list<FaceNew*>::iterator it=currentSolidFace.begin(); it != currentSolidFace.end(); ++it){
            currMesh->faces.push_back(*it);
        }

        for (std::list<Vert*>::iterator it=currentMeshVertices.begin(); it != currentMeshVertices.end(); ++it){
            currMesh->verts.push_back(*it);
        }

        for (std::list<EdgeNew*>::iterator it=currentMeshEdges.begin(); it != currentMeshEdges.end(); ++it){
            currMesh->edges.push_back(*it);
        }

        currMesh->setName(strdup($<string>2));

        InstanceNew* newInstance = createInstance(currMesh, currSession->verts, currReader, true);
        newInstance->setName(strdup($<string>2));
        currSession->instances.push_back(newInstance);

        double *min = (double*) malloc(sizeof(double));
        double *max = (double*) malloc(sizeof(double));
        double *step = (double*) malloc(sizeof(double));

        *min = 0.0;
        *max = 0.5;
        *step = 0.01;

        OffsetNew* currOffset = createOffset("autoOffset", min, max, step);

        currSession->offsets.push_back(currOffset);

    };

vertex:
    VERTEX NUMBER NUMBER NUMBER
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));

        *x = atof($<string>2);
        *y = atof($<string>3);
        *z = atof($<string>4);

        Vert * newVertex = NULL;
        for (Vert* currVert : currentMeshVertices){
            if ((abs(*currVert->x-*x) < 0.0000001) && (abs(*currVert->y-*y) < 0.0000001) && (abs(*currVert->z-*z) < 0.0000001)){
                newVertex = currVert;
                break;
            }
        }
        if (newVertex == NULL){
            newVertex = createVert (x, y, z);
            currentMeshVertices.push_back(newVertex);
        }

        currentFaceVertices.push_back(newVertex);
    };

vertexArgs:
    | vertexArgs vertex;

facetsArgs:
    | facetsArgs facets;

facets:
    FACET NORMAL NUMBER NUMBER NUMBER OUTER LOOP vertexArgs ENDLOOP ENDFACET
    {
        Reader* currReader = createReader(currSession);
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));

        *x = atof($<string>3);
        *y = atof($<string>4);
        *z = atof($<string>5);

        vector<Vert*> faceVert;
        for (Vert* vert : currentFaceVertices){
            faceVert.push_back(vert);
        }

        vector<double> normalCalc = getNormalFromVerts(faceVert);

        if (abs(normalCalc[0] - *x) > 0.0001 || abs(normalCalc[1] - *y) > 0.0001 || abs(normalCalc[2] - *z) > 0.0001){
            std::cout << stllineno << std::endl;
            std::cout << "=========" << std::endl;
            std::cout << normalCalc[0] << std::endl;
            std::cout << normalCalc[1] << std::endl;
            std::cout << normalCalc[2] << std::endl;
            std::cout << *x << std::endl;
            std::cout << *y << std::endl;
            std::cout << *z << std::endl;
        }

        FaceNew * newFace = createFace(currentFaceVertices, &currentMeshEdges, currReader, false);
        currentSolidFace.push_back(newFace);
        //std::cout << currentFaceVertices.size() << std::endl;
        currentFaceVertices.clear();
        //std::cout << "HELLO" << std::endl;
    };

numberValue:
    num {
        $<numPos.number>$ = $<number>1;
        $<numPos.string>$ = NULL;
    } | expr
    {
        $<numPos.string>$ = $<string>1;
        $<numPos.number>$ = 0;
    }
    ;


num:
    NUMBER
    {
        $<number>$ = (double)atof($1);
    }
    ;

numPosTok:
    NUMBER
    {
        $<numPos.string>$ = strdup($1);
        $<numPos.number>$ = stlcolumn;
    }
    ;

comment:
    COMMENT
    {
    }
    ;


variables:
  |
    variables VARIABLE {
        tempVariables.push_back($<string>2);
    }
    ;

surfaceArgs:
    {$<string>$ = "";}
    | SURFACE VARIABLE {
        $<string>$ = $<string>2;
    }
    ;

transformArgs:
    | transformArgs rotateArgs |  transformArgs translateArgs | transformArgs scaleArgs | transformArgs mirrorArgs
    ;

rotateArgs:
    ROTATE OPARENTHESES numberValue numberValue numberValue EPARENTHESES OPARENTHESES numberValue EPARENTHESES
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));
        double *angle = (double*) malloc(sizeof(double));


        if ($<numPos.string>3 == NULL){
            *x = $<numPos.number>3;
        }
        else{
            x = getBankValue2($<numPos.string>3, currSession);
        }

        if ($<numPos.string>4 == NULL){
            *y = $<numPos.number>4;
        }
        else{
            y = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *z = $<numPos.number>5;
        }
        else{
            z = getBankValue2($<numPos.string>5, currSession);
        }

        if ($<numPos.string>8 == NULL){
            *angle = $<numPos.number>8;
        }
        else{
            angle = getBankValue2($<numPos.string>8, currSession);
        }

        currentTransformations.push_back(createRotate(x, y, z, angle));

    }
    ;

translateArgs:
    TRANSLATE OPARENTHESES numberValue numberValue numberValue EPARENTHESES
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ($<numPos.string>3 == NULL){
            *x = $<numPos.number>3;
        }
        else{
            x = getBankValue2($<numPos.string>3, currSession);
        }

        if ($<numPos.string>4 == NULL){
            *y = $<numPos.number>4;
        }
        else{
            y = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *z = $<numPos.number>5;
        }
        else{
            z = getBankValue2($<numPos.string>5, currSession);
        }

        currentTransformations.push_back(createTranslate(x, y, z));
    }
    ;

scaleArgs:
    SCALE OPARENTHESES numberValue numberValue numberValue EPARENTHESES
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ($<numPos.string>3 == NULL){
            *x = $<numPos.number>3;
        }
        else{
            x = getBankValue2($<numPos.string>3, currSession);
        }

        if ($<numPos.string>4 == NULL){
            *y = $<numPos.number>4;
        }
        else{
            y = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *z = $<numPos.number>5;
        }
        else{
            z = getBankValue2($<numPos.string>5, currSession);
        }

        currentTransformations.push_back(createScale(x, y, z));
    }
    ;

mirrorArgs:
    MIRROR OPARENTHESES numberValue numberValue numberValue numberValue EPARENTHESES
    {
        double x = $<numPos.number>3;
        double y = $<numPos.number>4;
        double z = $<numPos.number>5;
        double w = $<numPos.number>5;

    }
    ;

faceArgs:
    | faceArgs faceMesh
    ;

instanceArgs:
    | instanceArgs instanceGroup
    ;

instanceGroup:
    INSTANCE VARIABLE VARIABLE surfaceArgs transformArgs END_INSTANCE
    {
        Reader* currReader = createReader(currSession);
        string instanceName = strdup($<string>2);
        string lookFor = strdup($<string>3);

        MeshNew * currentMesh = currReader->getMesh($<string>3);

        InstanceNew* newInstance;
        if (currentMesh != NULL) {
            newInstance = createInstance(currentMesh, currSession->verts, currReader, false);
            newInstance->setName(strdup($<string>2));
        }
        else{
            stlerror(currSession, "Incorrect vertex, face, or mesh name");
            YYABORT;
        }

        newInstance->transformations = currentTransformations;
        currentTransformations.clear();

        for (TransformationNew * t : newInstance->transformations){
            newInstance->applyTransformation(t);
        }

        string surfaceName = $<string>4;
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf($<string>4);
            if (currentSurface != NULL) {
                setSurface(newInstance, currentSurface);
            }
            else{
                stlerror(currSession, "Incorrect surface name");
                YYABORT;
            }
        }

        currentGroup.push_back(newInstance);
    }
    ;

faceDeleteArgs:
    | faceDeleteArgs faceDelete
    ;

instanceOffseSubdivide:
    INSTANCE VARIABLE
    {
        string instanceName = strdup($<string>2);
    };

instanceOffseSubdivideArgs:
    | instanceOffseSubdivideArgs instanceOffseSubdivide
    ;

subdivision:
    SUBDIVISION VARIABLE instanceOffseSubdivideArgs TYPE VARIABLE SUBDIVISIONS numberValue END_SUBDIVISION
    {
        double *subdivision = (double*) malloc(sizeof(double));


        if ($<numPos.string>7 == NULL){
            *subdivision = $<numPos.number>7;
        }
        else{
            subdivision = getBankValue2($<numPos.string>7, currSession);
        }

        SubdivisionNew* currSubdivision = createSubdivision(strdup($<string>3), strdup($<string>5), subdivision);
        currSession->subdivisions.push_back(currSubdivision);
    };

offset:
    OFFSET VARIABLE MIN numberValue MAX numberValue STEP numberValue END_OFFSET
    {
        double *min = (double*) malloc(sizeof(double));
        double *max = (double*) malloc(sizeof(double));
        double *step = (double*) malloc(sizeof(double));


        if ($<numPos.string>4 == NULL){
            *min = $<numPos.number>4;
        }
        else{
            min = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>6 == NULL){
            *max = $<numPos.number>6;
        }
        else{
            max = getBankValue2($<numPos.string>6, currSession);
        }

        if ($<numPos.string>8 == NULL){
            *step = $<numPos.number>8;
        }
        else{
            step = getBankValue2($<numPos.string>8, currSession);
        }

        OffsetNew* currOffset = createOffset(strdup($<string>2), min, max, step);

        currSession->offsets.push_back(currOffset);
    };

mesh:
    MESH VARIABLE faceArgs END_MESH
    {

        MeshNew* currMesh = createMesh();

        for (std::list<FaceNew*>::iterator it=currentMeshFaces.begin(); it != currentMeshFaces.end(); ++it){
            currMesh->faces.push_back(*it);
        }

        for (std::list<Vert*>::iterator it=currentMeshVertices.begin(); it != currentMeshVertices.end(); ++it){
            currMesh->verts.push_back(*it);
        }

        for (std::list<EdgeNew*>::iterator it=currentMeshEdges.begin(); it != currentMeshEdges.end(); ++it){
            currMesh->edges.push_back(*it);
        }

        currMesh->setName(strdup($<string>2));
        currSession->meshes.push_back(currMesh);

        currentMeshFaces.clear();
        currentMeshEdges.clear();
        currentMeshVertices.clear();
    }
    ;

group:
    GROUP VARIABLE instanceArgs END_GROUP
    {
        GroupNew* currGroup = createGroup(currentGroup);
        currGroup->setName(strdup($<string>2));
        currSession->groups.push_back(currGroup);
        currentGroup.clear();
    }
    ;

expr:
    OBRACE EXPR BANK_EXPR EBRACE
    {
        $<string>$ = $3;
    };

delete:
    BEG_DELETE faceDeleteArgs END_DELETE
    {
        Reader* currReader = createReader(currSession);
        for (std::string currFace : tempFaceDelete){
            currReader->deleteFace(currReader->getFace(currFace));
        }

        tempFaceDelete.clear();
    }
    ;

set:
    SET VARIABLE numPosTok numberValue numberValue numberValue
    {
        string currentSetName = $<string>2;
        double currentSetValue = (double)atof($<numPos.string>3);
        double currentSetStart = $<numPos.number>4;
        double currentSetEnd = $<numPos.number>5;
        double currentSetStepSize = $<numPos.number>6;
        string currentSetValueString = $<numPos.string>3;

        int begPos = $<numPos.number>3-currentSetValueString.length();
        int lengthValChar = currentSetValueString.length();

        SetNew * currentSet = createSet(currentSetName, currentSetValue, currentSetStart, currentSetEnd, currentSetStepSize, begPos, lengthValChar);

        currentSetList.push_back(currentSet);
    }
    ;

setArgs:
    | setArgs set |  setArgs comment
    ;

faceMesh:
    FACE VARIABLE parenthesisName surfaceArgs END_FACE
    {
        Reader* currReader = createReader(currSession);
        //std::cout << "Create face mesh" << std::endl;
        std::list<Vert*> verticesFace;

        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->getVert(*it);

            if (currentVertex != NULL) {
                verticesFace.push_back(currentVertex);
                bool found = false;
                for (Vert* currentMeshVertex: currentMeshVertices){
                    if (currentMeshVertex->index == currentVertex->index){
                        found = true;
                    }
                }
                if (found == false){
                    currentMeshVertices.push_back(currentVertex);
                }

            }
            else{
                stlerror(currSession, "Incorrect vertex name");
                YYABORT;
            }
        }

        FaceNew * newFace = createFace(verticesFace, &currentMeshEdges, currReader, false);
        setName(newFace, strdup($<string>2));

        string surfaceName = $<string>4;
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf($<string>4);
            if (currentSurface != NULL) {
                setSurface(newFace, currentSurface);
            }
            else{
                stlerror(currSession, "Incorrect surface name");
                YYABORT;
            }
        }

        currentMeshFaces.push_back(newFace);

        tempVariables.clear();
    }
    ;

bank:
    BANK VARIABLE setArgs END_BANK
    {
        BankNew * currentBank = createBank();
        currentBank->name = strdup($<string>2);
        currentBank->sets = currentSetList;
        currSession->banks.push_back(currentBank);
        currentSetList.clear();
    }
    ;

circle:
    CIRCLE VARIABLE OPARENTHESES numberValue numberValue EPARENTHESES END_CIRCLE
    {
        string name = $<string>2;
        double *num = (double*) malloc(sizeof(double));
        double *rad = (double*) malloc(sizeof(double));


        if ($<numPos.string>4 == NULL){
            *num = $<numPos.number>4;
        }
        else{
            num = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *rad = $<numPos.number>5;
        }
        else{
            rad = getBankValue2($<numPos.string>5, currSession);
        }

        CircleNew* currCircle = createCircle(num, rad);
        currCircle->setName(strdup($<string>2));

        currSession->circles.push_back(currCircle);
    };

tunnel:
    TUNNEL VARIABLE OPARENTHESES numberValue numberValue numberValue numberValue EPARENTHESES
  END_TUNNEL
    {
        Reader* currReader = createReader(currSession);
        string name = $<string>2;
        double *n = (double*) malloc(sizeof(double));
        double *ro = (double*) malloc(sizeof(double));
        double *ratio = (double*) malloc(sizeof(double));
        double *h = (double*) malloc(sizeof(double));

        if ($<numPos.string>4 == NULL){
            *n = $<numPos.number>4;
        }
        else{
            n = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *ro = $<numPos.number>5;
        }
        else{
            ro = getBankValue2($<numPos.string>5, currSession);
        }

        if ($<numPos.string>6 == NULL){
            *ratio = $<numPos.number>6;
        }
        else{
            ratio = getBankValue2($<numPos.string>6, currSession);
        }

        if ($<numPos.string>7 == NULL){
            *h = $<numPos.number>7;
        }
        else{
            h = getBankValue2($<numPos.string>7, currSession);
        }

        TunnelNew* currTunnel = createTunnel(n, ro, ratio, h, currReader);
        currTunnel->setName(strdup($<string>2));

        currSession->tunnels.push_back(currTunnel);
    }
    ;

funnel:
    FUNNEL VARIABLE OPARENTHESES numberValue numberValue numberValue numberValue EPARENTHESES
  END_FUNNEL
    {
        Reader* currReader = createReader(currSession);
        string name = $<string>2;
        double *n = (double*) malloc(sizeof(double));
        double *ro = (double*) malloc(sizeof(double));
        double *ratio = (double*) malloc(sizeof(double));
        double *h = (double*) malloc(sizeof(double));

        if ($<numPos.string>4 == NULL){
            *n = $<numPos.number>4;
        }
        else{
            n = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *ro = $<numPos.number>5;
        }
        else{
            ro = getBankValue2($<numPos.string>5, currSession);
        }

        if ($<numPos.string>6 == NULL){
            *ratio = $<numPos.number>6;
        }
        else{
            ratio = getBankValue2($<numPos.string>6, currSession);
        }

        if ($<numPos.string>7 == NULL){
            *h = $<number>7;
        }
        else{
            h = getBankValue2($<numPos.string>7, currSession);
        }

        FunnelNew* currFunnel = createFunnel(n, ro, ratio, h, currReader);
        currFunnel->setName(strdup($<string>2));

        currSession->funnels.push_back(currFunnel);
    }
    ;

parenthesisName:
    OPARENTHESES variables EPARENTHESES
    {
    }
    ;

face:
    FACE VARIABLE parenthesisName surfaceArgs END_FACE
    {
        Reader* currReader = createReader(currSession);
        std::list<Vert*> verticesFace;
        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->vert(*it);
            if (currentVertex != NULL) {
                verticesFace.push_back(currentVertex);
            }
            else{
                stlerror(currSession, "Incorrect vertex name");
                YYABORT;
            }
        }

        FaceNew * newFace = createFace(verticesFace, &(currSession->edges), currReader, false);

        setName(newFace, strdup($<string>2));


        string surfaceName = $<string>4;
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf($<string>4);
            if (currentSurface != NULL) {
                setSurface(newFace, currentSurface);
            }
            else{
                stlerror(currSession, "Incorrect surface name");
                YYABORT;
            }
        }

        currSession->faces.push_back(newFace);

        tempVariables.clear();
    }
    ;

faceDelete:
    FACE VARIABLE END_FACE
    {
        tempFaceDelete.push_back($<string>2);
    }
    ;

polyline:
    POLYLINE VARIABLE parenthesisName END_POLYLINE
    {
        Reader* currReader = createReader(currSession);
        // Create list of vertices of face.
        std::list<Vert*> verticesPolyline;
        for (std::vector<string>::iterator it = tempVariables.begin() ; it != tempVariables.end(); ++it){
            Vert * currentVertex = currReader->getVert(*it);
            if (currentVertex != NULL) {
                verticesPolyline.push_back(currentVertex);
            }
            else{
                stlerror(currSession, "Incorrect vertex name");
                YYABORT;
            }
        }

        PolylineNew* currPolyline = createPolylineNew(verticesPolyline);
        currPolyline->setName(strdup($<string>2));

        currSession->polylines.push_back(currPolyline);
        tempVariables.clear();
    }
    ;

instance:
    INSTANCE VARIABLE VARIABLE surfaceArgs transformArgs END_INSTANCE
    {
        Reader* currReader = createReader(currSession);
        string instanceName = strdup($<string>2);
        string lookFor = strdup($<string>3);

        MeshNew * currentMesh = currReader->getMesh($<string>3);

        InstanceNew* newInstance = NULL;
        if (currentMesh != NULL) {
            newInstance = createInstance(currentMesh, currSession->verts, currReader, true);
        }
        else{
            GroupNew * currentGroup = currReader->getGroup($<string>3);
            if (currentGroup != NULL) {
                newInstance = createInstance(currentGroup, currSession->verts, currReader);
            }
            else{
                stlerror(currSession, "Incorrect vertex, face, or mesh name");
                YYABORT;
            }
        }

        newInstance->setName(strdup($<string>2));
        newInstance->transformations = currentTransformations;
        currentTransformations.clear();

        for (TransformationNew * t : newInstance->transformations){
            newInstance->applyTransformation(t);
        }

        string surfaceName = $<string>4;
        // Check if a surface has been applied.
        if (surfaceName.length() != 0){
            Surface * currentSurface = currReader->surf($<string>4);
            if (currentSurface != NULL) {
                setSurface(newInstance, currentSurface);
            }
            else{
                stlerror(currSession, "Incorrect surface name");
                YYABORT;
            }
        }

        currSession->instances.push_back(newInstance);
    }
    ;

object:
    OBJECT VARIABLE parenthesisName END_OBJECT
    {
    }
    ;

surface:
    SURFACE VARIABLE COLOR OPARENTHESES numberValue numberValue numberValue EPARENTHESES END_SURFACE
    {
        double *r = (double*) malloc(sizeof(double));
        double *g = (double*) malloc(sizeof(double));
        double *b = (double*) malloc(sizeof(double));

        if ($<numPos.string>5 == NULL){
            *r = $<numPos.number>5;
        }
        else{
            r = getBankValue2($<numPos.string>5, currSession);
        }

        if ($<numPos.string>6 == NULL){
            *g = $<numPos.number>6;
        }
        else{
            g = getBankValue2($<numPos.string>6, currSession);
        }

        if ($<numPos.string>7 == NULL){
            *b = $<numPos.number>7;
        }
        else{
            b = getBankValue2($<numPos.string>7, currSession);
        }

        currSession->surfaces.push_back(createSurface(r, g, b, strdup($<string>2)));
    }
    ;

point:
    BEG_POINT VARIABLE OPARENTHESES numberValue numberValue numberValue EPARENTHESES END_POINT
    {
        double *x = (double*) malloc(sizeof(double));
        double *y = (double*) malloc(sizeof(double));
        double *z = (double*) malloc(sizeof(double));


        if ($<numPos.string>4 == NULL){
            *x = $<numPos.number>4;
        }
        else{
            x = getBankValue2($<numPos.string>4, currSession);
        }

        if ($<numPos.string>5 == NULL){
            *y = $<numPos.number>5;
        }
        else{
            y = getBankValue2($<numPos.string>5, currSession);
        }

        if ($<numPos.string>6 == NULL){
            *z = $<numPos.number>6;
        }
        else{
            z = getBankValue2($<numPos.string>6, currSession);
        }

        Vert * newVertex = createVert (x, y, z);
        newVertex->setName(strdup($<string>2));
        currSession->verts.push_back(newVertex);
    }
    ;
