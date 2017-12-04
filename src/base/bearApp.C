#include "bearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<bearApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

bearApp::bearApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  bearApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  bearApp::associateSyntax(_syntax, _action_factory);
}

bearApp::~bearApp() {}

// External entry point for dynamic application loading
extern "C" void
bearApp__registerApps()
{
  bearApp::registerApps();
}
void
bearApp::registerApps()
{
  registerApp(bearApp);
}

void
bearApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
bearApp__registerObjects(Factory & factory)
{
  bearApp::registerObjects(factory);
}
void
bearApp::registerObjects(Factory & /*factory*/)
{
}

void
bearApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
bearApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  bearApp::associateSyntax(syntax, action_factory);
}
void
bearApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
