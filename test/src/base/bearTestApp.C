#include "bearTestApp.h"
#include "bearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<bearTestApp>()
{
  InputParameters params = validParams<bearApp>();
  return params;
}

bearTestApp::bearTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  bearApp::registerObjectDepends(_factory);
  bearApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  bearApp::associateSyntaxDepends(_syntax, _action_factory);
  bearApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    bearTestApp::registerObjects(_factory);
    bearTestApp::associateSyntax(_syntax, _action_factory);
  }
}

bearTestApp::~bearTestApp() {}

// External entry point for dynamic application loading
extern "C" void
bearTestApp__registerApps()
{
  bearTestApp::registerApps();
}
void
bearTestApp::registerApps()
{
  registerApp(bearApp);
  registerApp(bearTestApp);
}

// External entry point for dynamic object registration
extern "C" void
bearTestApp__registerObjects(Factory & factory)
{
  bearTestApp::registerObjects(factory);
}
void
bearTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
bearTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  bearTestApp::associateSyntax(syntax, action_factory);
}
void
bearTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
